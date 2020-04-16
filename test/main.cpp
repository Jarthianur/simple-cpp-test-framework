/*
    Copyright (C) 2017 Jarthianur

    This file is part of simple-cpp-test-framework.

    simple-cpp-test-framework is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    simple-cpp-test-framework is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with simple-cpp-test-framework.  If not, see <https://www.gnu.org/licenses/>.
*/

#define SCTF_EXTERN_EPSILON

#include <iostream>

#include "basic_tests.h"
#include "sctf.hpp"

SCTF_EPSILON(0.000001)

using namespace sctf;

int main(int, char**) {
    auto rep   = console_reporter::create(std::cout, true, true);
    auto repx  = xml_reporter::create("test.xml", true);
    auto repmd = markdown_reporter::create("test.md", true);

    try {
        basic_tests();
    } catch (std::exception const& e) {
        std::cout << "Basic tests have failed! [" << e.what() << "]" << std::endl;
        return 1;
    } catch (...) {
        std::cout << "Basic tests have failed!" << std::endl;
        return 1;
    }
    std::cout << "Basic tests have succeeded!" << std::endl;

    return rep->report() + repx->report() + repmd->report() > 0 ? 1 : 0;
}

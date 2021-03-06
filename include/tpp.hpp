/*
    Copyright (C) 2017  Jarthianur

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/// @file

#ifndef TPP_TPP_HPP
#define TPP_TPP_HPP

#include "assert/assert.hpp"
#include "assert/equality.hpp"
#include "assert/ordering.hpp"
#include "assert/range.hpp"
#include "assert/regex.hpp"

#include "api.hpp"
#include "regex.hpp"
#include "runner.hpp"

/**
 * Define a default main function, which performs all tests and allows modification via command line arguments.
 */
#define TPP_DEFAULT_MAIN                                  \
    auto main(int argc_, char const** argv_)->int {       \
        return tpp::runner::instance().run(argc_, argv_); \
    }

#endif  // TPP_TPP_HPP

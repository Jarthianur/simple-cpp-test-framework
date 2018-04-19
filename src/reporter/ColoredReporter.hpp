/*
 Copyright_License {

 Copyright (C) 2017 Julian P. Becht
 Author: Julian P. Becht

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License version 3
 as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 }
 */

#ifndef REPORTER_COLOREDREPORTER_HPP_
#define REPORTER_COLOREDREPORTER_HPP_

#include <cstdint>
#include <iostream>
#include <string>

#include "../testsuite/TestCase.hpp"
#include "../testsuite/TestStats.hpp"
#include "../testsuite/TestSuite.hpp"
#include "../util/types.h"
#include "AbstractReporter.hpp"

namespace testsuite
{
namespace reporter
{
// ANSI colors
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
// ANSI reset colors
#define ANSI_RESET "\x1b[0m"

/**
 * Concrete reporter,
 * featuring colored plain text format.
 */
class ColoredReporter : public AbstractReporter
{
public:
    /**
     * c'tor with stream
     */
    ColoredReporter(std::ostream& stream) : AbstractReporter(stream)
    {}

    /**
     * c'tor with filename
     */
    ColoredReporter(const char* fnam) : AbstractReporter(fnam)
    {}

    /**
     * d'tor
     */
    virtual ~ColoredReporter() noexcept
    {}

protected:
    /**
     * impl
     */
    virtual void reportTestSuite(TestSuite_shared ts) override
    {
        *this << "Run Testsuite [" << ts->mName << "]; time = " << ts->getTime() << "ms"
              << LF;

        abs_tests += ts->getTestStats().getNumTests();
        abs_fails += ts->getTestStats().getNumFails();
        abs_errs += ts->getTestStats().getNumErrs();
        abs_time += ts->getTime();

        AbstractReporter::reportTestSuite(ts);
    }

    /**
     * impl
     */
    virtual void reportTestCase(const TestCase& tc) override
    {
        *this << SPACE << "Run Testcase [" << tc.mName << "](" << tc.mClassname
              << "); time = " << tc.getDuration() << "ms" << LF << XSPACE;
        switch(tc.getState())
        {
            case TestCase::ERROR:
                *this << ANSI_MAGENTA << "ERROR! " << tc.getErrMsg();
                break;
            case TestCase::FAILED:
                *this << ANSI_RED << "FAILED! " << tc.getErrMsg();
                break;
            case TestCase::PASSED:
                *this << ANSI_GREEN << "PASSED!";
                break;
            default:
                break;
        }
        *this << ANSI_RESET << LF;
    }

    /**
     * impl
     */
    inline virtual void beginReport() override
    {}

    /**
     * impl
     */
    inline virtual void endReport() override
    {
        if(abs_fails >= (abs_tests + 1) / 2)
        {
            *this << ANSI_YELLOW;
        }
        else
        {
            *this << ANSI_CYAN;
        }
        *this << "Result:: passed: " << abs_tests - abs_fails - abs_errs << "/"
              << abs_tests << " ; failed: " << abs_fails << "/" << abs_tests
              << " ; errors: " << abs_errs << "/" << abs_tests << " ; time = " << abs_time
              << "ms" << ANSI_RESET << LF;
    }

private:
    double abs_time         = 0;
    std::uint32_t abs_tests = 0;
    std::uint32_t abs_fails = 0;
    std::uint32_t abs_errs  = 0;
};

/**
 * Factory method for colored text reporter
 */
inline AbstractReporter_shared createColoredReporter(std::ostream& stream = std::cout)
{
    return AbstractReporter_shared(new ColoredReporter(stream));
}

/**
 * Factory method for colored text reporter
 */
inline AbstractReporter_shared createColoredReporter(const char* file)
{
    return AbstractReporter_shared(new ColoredReporter(file));
}

}  // reporter
}  // testsuite

#endif /* REPORTER_COLOREDREPORTER_HPP_ */

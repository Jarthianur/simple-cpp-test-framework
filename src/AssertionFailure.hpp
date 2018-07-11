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

#ifndef SRC_ASSERTIONFAILURE_HPP_
#define SRC_ASSERTIONFAILURE_HPP_

#include <exception>
#include <string>

namespace sctf
{
/**
 * @brief Represent a failed assertion.
 */
class AssertionFailure : public std::exception
{
public:
    /**
     * @brief Constructor
     * @param msg The base error message
     * @param file The source file where the assertion took place
     * @param line The source line of the assertion
     */
    AssertionFailure(const std::string& msg, const char* file, int line)
        : std::exception(), m_msg(msg + " at " + file + ":" + std::to_string(line))
    {}

    /**
     * @brief Destructor
     */
    virtual ~AssertionFailure() noexcept
    {}

    /**
     * @brief Get the error message.
     * @return the message
     */
    inline const char* what() const noexcept override
    {
        return m_msg.c_str();
    }

private:
    /// @brief The error message
    const std::string m_msg;
};

}  // namespace sctf

#endif  // SRC_ASSERTIONFAILURE_HPP_
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

#ifndef TPP_ASSERT_ORDERING_HPP
#define TPP_ASSERT_ORDERING_HPP

#include "assert/assert.hpp"

TPP_DEFINE_ASSERTION(assert_greater, "greater than", v_ > e_)
TPP_DEFINE_ASSERTION(assert_less, "less than", v_ < e_)
TPP_PROVIDE_ASSERTION(assert_greater, GT)
TPP_PROVIDE_ASSERTION(assert_less, LT)

/**
 * Assert a value to be greater than another value.
 * This is equivalent to using ASSERT with GT.
 *
 * @param ... is the value in question, followed by the value to compare against.
 *
 * EXAMPLE:
 * @code
 * ASSERT_GT(2, 1);
 * @endcode
 */
#define ASSERT_GT(...)                                                        \
    tpp::intern::assert::make_assertion<tpp::intern::assert::assert_greater>( \
      __VA_ARGS__, false, tpp::intern::assert::loc{__FILE__, __LINE__})

/**
 * Assert a value to be not greater than another value.
 * This is equivalent to using ASSERT_NOT with GT.
 *
 * @param ... is the value in question, followed by the value to compare against.
 *
 * EXAMPLE:
 * @code
 * ASSERT_NOT_GT(2, 2);
 * @endcode
 */
#define ASSERT_NOT_GT(...)                                                    \
    tpp::intern::assert::make_assertion<tpp::intern::assert::assert_greater>( \
      __VA_ARGS__, true, tpp::intern::assert::loc{__FILE__, __LINE__})

/**
 * Assert a value to be less than another value.
 * This is equivalent to using ASSERT with LT.
 *
 * @param ... is the value in question, followed by the value to compare against.
 *
 * EXAMPLE:
 * @code
 * ASSERT_LT(1, 2);
 * @endcode
 */
#define ASSERT_LT(...)                                                     \
    tpp::intern::assert::make_assertion<tpp::intern::assert::assert_less>( \
      __VA_ARGS__, false, tpp::intern::assert::loc{__FILE__, __LINE__})

/**
 * Assert a value to be not less than another value.
 * This is equivalent to using ASSERT_NOT with LT.
 *
 * @param ... is the value in question, followed by the value to compare against.
 *
 * EXAMPLE:
 * @code
 * ASSERT_NOT_LT(1, 1);
 * @endcode
 */
#define ASSERT_NOT_LT(...)                                                 \
    tpp::intern::assert::make_assertion<tpp::intern::assert::assert_less>( \
      __VA_ARGS__, true, tpp::intern::assert::loc{__FILE__, __LINE__})

#endif  // TPP_ASSERT_ORDERING_HPP

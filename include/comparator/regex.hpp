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

#ifndef SCTF_COMPARATOR_REGEX_HPP
#define SCTF_COMPARATOR_REGEX_HPP

#include <regex>

#include "comparator/comparator.hpp"

SCTF_COMPARATOR(match, "matching", std::regex_match(actual_value, std::regex(expected_value)))
SCTF_PROVIDE_COMPARATOR(match, MATCH)

SCTF_COMPARATOR(like, "like", std::regex_search(actual_value, std::regex(expected_value)))
SCTF_PROVIDE_COMPARATOR(like, LIKE)

#endif  // SCTF_COMPARATOR_REGEX_HPP

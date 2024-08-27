//   ___ _ __ _ __ ___  _ __ 
//  / _ \ '__| '__/ _ \| '__|  error - error codes & categories
// |  __/ |  | | | (_) | |     --------------------------------
//  \___|_|  |_|  \___/|_|     https://github.com/meanbot/error
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#pragma once


#include <cstdint>
#include <string>
#include "meanbot/error_types.hpp"
#include <xxh32.hpp>


//error project does not have a custom namespace (e.g. error) !
namespace meanbot
{

static inline constexpr error_category_type generate_error_category(const char *categ_name)
{
	return (error_category_type)xxh32::hash(categ_name, (uint32_t)std::char_traits<char>::length(categ_name), 0);
}

} //namespace meanbot

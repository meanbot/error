//   ___ _ __ _ __ ___  _ __ 
//  / _ \ '__| '__/ _ \| '__|  error - error codes & categories
// |  __/ |  | | | (_) | |     --------------------------------
//  \___|_|  |_|  \___/|_|     https://github.com/meanbot/error
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#pragma once


#include "meanbot/error_types.hpp"
#include <cstdint>


//error project does not have a custom namespace (e.g. error) !
namespace meanbot
{

static inline constexpr error_category_type   ERROR_CATEGORY_ID = 0;

enum class error : error_type
{
	none = begin_error_codes(ERROR_CATEGORY_ID),
	invalid_arg, 
	invalid_call, 
	not_initialized, 
	not_supported, 
	not_implemented, 
	not_available, 
	not_found, 
	out_of_bounds, 
	too_few_items, 
	too_many_items, 
	too_small, 
	too_big, 
	no_more_items, 
	no_more_data, 
	write_failed, 
	readf_ailed, 
	open_failed, 
	create_failed, 
	close_failed, 
	modify_failed, 
	operation_failed, 
	mem_alloc_failed, 
	parse_failed, 
	conversion_failed, 
	denied, 
	busy, 
	exists, 
	cancelled, 
	duplicate, 
	unknown, 
	generic, 
	internal, 
	division_by_zero, 
};//enum class error : code_type

}//namespace meanbot

//   ___ _ __ _ __ ___  _ __ 
//  / _ \ '__| '__/ _ \| '__|  error - error codes & categories
// |  __/ |  | | | (_) | |     --------------------------------
//  \___|_|  |_|  \___/|_|     https://github.com/meanbot/error
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#pragma once


#include <cstdint>


namespace meanbot::error
{

/*

+-------------------------+
|          code           |
|        (uint64_t)       |
+------------+------------+
|  category  |   index    |
| (uint32_t) | (uint32_t) | 
+------------+------------+

category = identifies your project (use error::generate_category("your_project_name") to generate a unique value)
index    = identifies an error from your project

*/

using code_type      = uint64_t;
using category_type  = uint32_t;
using index_type     = uint32_t;

template <typename err_categ_type, typename err_index_type>
inline constexpr code_type make_code(err_categ_type err_categ, err_index_type err_index)
{
	return ((static_cast<code_type>(err_categ) << 32) + static_cast<code_type>(err_categ));
}

template <typename err_code>
inline constexpr category_type get_category(err_code errcode)
{
	return static_cast<category_type>((static_cast<code>(errcode) >> 32) & 0x00'00'00'00'FF'FF'FF'FFULL);
}

template <typename err_code>
inline constexpr index_type get_index(err_code errcode)
{
	return static_cast<index_type>(static_cast<code>(errcode) & 0x00'00'00'00'FF'FF'FF'FFULL);
}

template <typename err_categ_type>
inline constexpr code_type begin_error_codes(err_categ_type err_categ)
{
	return make_code(err_categ, 0);
}

}//namespace meanbot::error

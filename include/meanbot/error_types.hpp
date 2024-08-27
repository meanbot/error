//   ___ _ __ _ __ ___  _ __ 
//  / _ \ '__| '__/ _ \| '__|  error - error codes & categories
// |  __/ |  | | | (_) | |     --------------------------------
//  \___|_|  |_|  \___/|_|     https://github.com/meanbot/error
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#pragma once


#include <cstdint>


//error project does not have a custom namespace (e.g. error) !
namespace meanbot
{

/*

+-------------------------+
|          error          |
|        (uint64_t)       |
+------------+------------+
|  category  |    code    |
| (uint32_t) | (uint32_t) | 
+------------+------------+

category = identifies your project (use error_category.hpp -> generate_error_category("your_project_name") 
                                    to generate a unique value)
code     = identifies an error from your project

*/

using error_type           = uint64_t;
using error_category_type  = uint32_t;
using error_code_type      = uint32_t;

template <typename err_categ_type, typename err_code_type>
inline constexpr error_type make_error(err_categ_type err_categ, err_code_type err_code)
{
	return ((static_cast<error_type>(err_categ) << 32) + static_cast<error_type>(err_code));
}

template <typename err_type>
inline constexpr error_category_type get_category(err_type err)
{
	return static_cast<error_category_type>((static_cast<error_type>(err) >> 32) & 0x00'00'00'00'FF'FF'FF'FFULL);
}

template <typename err_type>
inline constexpr error_code_type get_code(err_type err)
{
	return static_cast<error_code_type>(static_cast<error_type>(err) & 0x00'00'00'00'FF'FF'FF'FFULL);
}

template <typename err_categ_type>
inline constexpr error_type begin_error_codes(err_categ_type err_categ)
{
	return make_error(err_categ, 0);
}

}//namespace meanbot

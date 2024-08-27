//   ___ _ __ _ __ ___  _ __ 
//  / _ \ '__| '__/ _ \| '__|  error - error codes & categories
// |  __/ |  | | | (_) | |     --------------------------------
//  \___|_|  |_|  \___/|_|     https://github.com/meanbot/error
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#include <meanbot/error_version.hpp>
#include <meanbot/error_types.hpp>
#include <meanbot/error.hpp>
#include <meanbot/error_category.hpp>
#include <fmt/core.h>


namespace myproject
{

static constexpr auto ERROR_CATEGORY_ID = meanbot::generate_error_category("myproject");

enum class error : meanbot::error_type
{
	fail1 = meanbot::begin_error_codes(ERROR_CATEGORY_ID),
	fail2,
	fail3
};

}//namespace myproject


int main(int argc, char *argv[])
{
	fmt::print("version                       = {}\n", meanbot::error_version::STRING);

	fmt::print("error <none>                  = {}\n", (meanbot::error_type)meanbot::error::none);
	fmt::print("error <cancelled>             = {}\n", (meanbot::error_type)meanbot::error::cancelled);
	fmt::print("error <division_by_zero>      = {}\n", (meanbot::error_type)meanbot::error::division_by_zero);

	fmt::print("categ_id('some_categ_1')      = {}\n", meanbot::generate_error_category("some_categ_1"));
	fmt::print("categ_id('some_categ_2')      = {}\n", meanbot::generate_error_category("some_categ_2"));
	fmt::print("categ_id('some_categ_3')      = {}\n", meanbot::generate_error_category("some_categ_3"));

	fmt::print("myproject::error::fail1       = {}\n", (meanbot::error_type)myproject::error::fail1);
	fmt::print("myproject::error::fail2       = {}\n", (meanbot::error_type)myproject::error::fail2);
	fmt::print("myproject::error::fail3       = {}\n", (meanbot::error_type)myproject::error::fail3);

	fmt::print("myproject::ERROR_CATEGORY_ID  = {}\n", myproject::ERROR_CATEGORY_ID);

	fmt::print("myproject::error::fail1 categ = {}\n", meanbot::get_category(myproject::error::fail1));
	fmt::print("myproject::error::fail1 code  = {}\n", meanbot::get_code(myproject::error::fail1));
	fmt::print("myproject::error::fail2 categ = {}\n", meanbot::get_category(myproject::error::fail2));
	fmt::print("myproject::error::fail2 code  = {}\n", meanbot::get_code(myproject::error::fail2));
	fmt::print("myproject::error::fail3 categ = {}\n", meanbot::get_category(myproject::error::fail3));
	fmt::print("myproject::error::fail3 code  = {}\n", meanbot::get_code(myproject::error::fail3));

	return 0;
}

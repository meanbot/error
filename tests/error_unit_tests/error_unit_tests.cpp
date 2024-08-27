//   ___ _ __ _ __ ___  _ __ 
//  / _ \ '__| '__/ _ \| '__|  error - error codes & categories
// |  __/ |  | | | (_) | |     --------------------------------
//  \___|_|  |_|  \___/|_|     https://github.com/meanbot/error
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#include <fmt/core.h>
#include <catch2/catch_all.hpp>


CATCH_TEST_CASE("test", "")
{
	CATCH_REQUIRE(1 == 1);
}

int main(int argc, char *argv[])
{
	int   result = Catch::Session().run(argc, argv);

	return result;
}

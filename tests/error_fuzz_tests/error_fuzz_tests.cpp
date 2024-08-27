//   ___ _ __ _ __ ___  _ __ 
//  / _ \ '__| '__/ _ \| '__|  error - error codes & categories
// |  __/ |  | | | (_) | |     --------------------------------
//  \___|_|  |_|  \___/|_|     https://github.com/meanbot/error
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#include <cstdint>
#include <fmt/core.h>


extern "C" int LLVMFuzzerInitialize(int *argc, char ***argv)
{
	(void) argc;
	(void) argv;

	return 0;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t data_size)
{
	(void) data;
	(void) data_size;

	return 0;
}

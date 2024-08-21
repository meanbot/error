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


namespace meanbot::error
{

// https://semver.org
struct version final
{
	static constexpr std::string_view   NAME          = "meanbot.error";
	static constexpr std::string_view   DESCRIPTION   = "error codes & categories";
	static constexpr std::string_view   URL           = "https://github.com/meanbot/error";

	static constexpr uint32_t           MAJOR         = 0; // when you make incompatible API changes
	static constexpr uint32_t           MINOR         = 0; // when you add functionality in a backward compatible manner
	static constexpr uint32_t           PATCH         = 1; // when you make backward compatible bug fixes
	static constexpr std::string_view   PRERELEASE    = "";
	static constexpr std::string_view   BUILDMETADATA = "";

	// <MAJOR>.<MINOR>.<PATCH>[-<PRERELEASE>][+BUILDMETADATA]
	static constexpr std::string_view   STRING        = "0.0.1";
}; //struct version

} //namespace meanbot::error

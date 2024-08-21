
#include "precomp.hpp"
#include "meanbot/error/category.hpp"
#include <xxh32.hpp>


namespace meanbot::error
{

constexpr uint32_t generate_category(const char *categ_name)
{
	return xxh32::hash(categ_name, (uint32_t)std::char_traits<char>::length(categ_name), 0);
}

}//namespace meanbot::error

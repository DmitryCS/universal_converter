#include "catch2/catch.hpp"
#include "udecoder/dummy.h"

using namespace udecoder;

TEST_CASE("sum", "[sum,arithmetic]")
{
	CHECK(sum("65498273", "564987201267") == "565052699540");
}

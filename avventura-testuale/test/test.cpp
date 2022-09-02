// Authors: Lorenzo Colombo - Lorenzo De Filippo - Giovanni Nerviani
#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
	EXPECT_STRNE("Hello", "World");

	EXPECT_EQ(7 * 6, 42);
};

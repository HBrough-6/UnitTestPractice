/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// TEST(PasswordTest, single_letter_password)
// {
// 	Password my_password;
// 	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
// }

// TEST(PasswordTest, two_leading_letters)
// {
// 	Password my_password;
// 	ASSERT_EQ(2, my_password.count_leading_characters("aab"));
// }

// TEST(PasswordTest, empty_password)
// {
// 	Password my_password;
// 	ASSERT_EQ(0, my_password.count_leading_characters(""));
// }

TEST(PasswordTest, mixed_empty_password)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case(""));
}

TEST(PasswordTest, mixed_one_lowercase_letter)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("a"));
}

TEST(PasswordTest, mixed_one_uppercase_letter)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("A"));
}

TEST(PasswordTest, mixed_one_number)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("1"));
}

TEST(PasswordTest, mixed_one_special_character)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("@"));
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Aa"));
}

TEST(PasswordTest, mixed_symbol_lowercase)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("$a"));
}

TEST(PasswordTest, mixed_case_password_Long)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("AAAAAAAAAAAAAAAAb"));
}

TEST(PasswordTest, mixed_case_lower_then_upper)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("bA"));
}

TEST(PasswordTest, mixed_case_password_with_numbers)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("A1a"));
}

TEST(PasswordTest, mixed_case_password_with_special_characters)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("A@a"));
}

TEST(PasswordTest, mixed_case_password_with_numbers_and_special_characters)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("A1@a"));
}

TEST(PasswordTest, mixed_case_password_with_only_special_characters)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("@#"));
}

TEST(PasswordTest, mixed_case_password_with_only_numbers)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("123"));
}

TEST(PasswordTest, mixed_case_password_with_only_lowercase_letters)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("abc"));
}

TEST(PasswordTest, mixed_case_password_with_only_uppercase_letters)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("ABC"));
}

TEST(PasswordTest, mixed_case_password_with_space)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("A b"));
}

TEST(PasswordTest, mixed_case_password_with_leading_space)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case(" Ab"));
}

TEST(PasswordTest, mixed_case_password_space_lowercase)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case(" b"));
}

TEST(PasswordTest, unique_empty)
{
	Password my_password;
	ASSERT_EQ(0, my_password.unique_characters(""));
}

TEST(PasswordTest, unique_single_space)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters(" "));
}

TEST(PasswordTest, duplicate_space)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("      "));
}

TEST(PasswordTest, unique_single_lowercase_letter)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("a"));
}

TEST(PasswordTest, duplicate_lowercase_letter)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("aaaaaaa"));
}

TEST(PasswordTest, unique_single_uppercase_letter)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("A"));
}

TEST(PasswordTest, duplicate_uppercase_letter)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("AAAAAAA"));
}

TEST(PasswordTest, unique_single_number)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("1"));
}

TEST(PasswordTest, duplicate_single_number)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("11111111"));
}

TEST(PasswordTest, unique_single_special_character)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("@"));
}

TEST(PasswordTest, unique_duplicate_special_character)
{
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("@@@@"));
}

TEST(PasswordTest, unique_characters_lowercase)
{
	Password my_password;
	ASSERT_EQ(5, my_password.unique_characters("abcde"));
}

TEST(PasswordTest, unique_characters_uppercase)
{
	Password my_password;
	ASSERT_EQ(5, my_password.unique_characters("ABCDE"));
}

TEST(PasswordTest, unique_characters_special)
{
	Password my_password;
	ASSERT_EQ(5, my_password.unique_characters("!@#$%"));
}

TEST(PasswordTest, unique_characters_numbers)
{
	Password my_password;
	ASSERT_EQ(5, my_password.unique_characters("12345"));
}

TEST(PasswordTest, unique_characters_mixed)
{
	Password my_password;
	ASSERT_EQ(10, my_password.unique_characters("aaA1!bB2@cC3#"));
}
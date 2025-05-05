/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, Secret_match)
{
  Guesser object("Secret");
  ASSERT_EQ(true,  object.match("Secret"));
}

TEST(GuesserTest, Secret_Secret2_not_match)
{
  Guesser object("Secret");
  ASSERT_EQ(false,  object.match("Secret2"));
}

TEST(GuesserTest, Secret_Over32char_match)
{
  Guesser object("SecretSecretSecretSecretSecretSecretSecret");
  ASSERT_EQ(true,  object.match("SecretSecretSecretSecretSecretSe"));
}

TEST(GuesserTest, Secret_Over32char_guess_Over32_not_match)
{
  Guesser object("SecretSecretSecretSecretSecretSecretSecret");
  ASSERT_EQ(false,  object.match("SecretSecretSecretSecretSecretSe2"));
}

TEST(GuesserTest, case_sensitive_Secret_secret_not_match)
{
  Guesser object("Secret");
  ASSERT_EQ(false,  object.match("secret"));
}

TEST(GuesserTest, case_sensitive_Secret_sEcret_not_match2)
{
  Guesser object("Secret");
  ASSERT_EQ(false,  object.match("sEcret"));
}

TEST(GuesserTest, case_sensitive_secret_Secret_not_match2)
{
  Guesser object("secret");
  ASSERT_EQ(false,  object.match("Secret"));
}

TEST(GuesserTest, case_sensitive_secret_sEcret_not_match2)
{
  Guesser object("secret");
  ASSERT_EQ(false,  object.match("sEcret"));
}

TEST(GuesserTest, initial_3_remaining)
{
  Guesser object("Secret");
  ASSERT_EQ(3, object.remaining());
}

TEST(GuesserTest, Secret_Secret2_2_remaining)
{
  Guesser object("Secret");
  object.match("Secret2");
  ASSERT_EQ(2, object.remaining());
}

TEST(GuesserTest, Secret_Secret2_Secret3_1_remaining)
{
  Guesser object("Secret");
  object.match("Secret2");
  object.match("Secret3");
  ASSERT_EQ(1, object.remaining());
}

TEST(GuesserTest, Secret_Secret2_Secret3_Secret4_0_remaining)
{
  Guesser object("Secret");
  object.match("Secret2");
  object.match("Secret3");
  object.match("Secret4");
  ASSERT_EQ(0, object.remaining());
}
TEST(GuesserTest, Secret_Secret2_Secret3_Secret4_Secret_locked)
{
  Guesser object("Secret");
  object.match("Secret2");
  object.match("Secret3");
  object.match("Secret4");
  ASSERT_EQ(false, object.match("Secret"));
}


TEST(GuesserTest, distance_over_2_Secret_00Secret_locked_2remaining)
{
  Guesser object("Secret");
  object.match("00Secret");
  ASSERT_EQ(2, object.remaining());
}

TEST(GuesserTest, distance_over_2_Secret_00Secret_locked)
{
  Guesser object("Secret");
  object.match("00Secret");
  ASSERT_EQ(false, object.match("Secret"));
}

TEST(GuesserTest, distance_over_2_Secret_Secret000_locked_2_remaining)
{
  Guesser object("Secret");
  object.match("Secret000");
  ASSERT_EQ(2, object.remaining());
}

TEST(GuesserTest, distance_over_2_Secret_Secret000_locked)
{
  Guesser object("Secret");
  object.match("Secret000");
  ASSERT_EQ(false, object.match("Secret"));
}

TEST(GuesserTest, distance_over_2_Secret_Sec_0_locked_2remaining)
{
  Guesser object("Secret");
  object.match("Sec");
  ASSERT_EQ(2, object.remaining());
}

TEST(GuesserTest, distance_over_2_Secret_Sec_locked)
{
  Guesser object("Secret");
  object.match("Sec");
  ASSERT_EQ(false, object.match("Secret"));
}

TEST(GuesserTest, distance_over_2_Secret_Seaaat_locked_2remaining)
{
  Guesser object("Secret");
  object.match("Seaaat");
  ASSERT_EQ(2, object.remaining());
}
TEST(GuesserTest, distance_over_2_Secret_Seaaat_locked)
{
  Guesser object("Secret");
  object.match("Seaaat");
  ASSERT_EQ(false, object.match("Secret"));
}
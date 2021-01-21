/*
** EPITECH PROJECT, 2021
** Valentin Sene's CPP template
** File description:
** gtest assertions and example
*/

#include <gtest/gtest.h>
#include <string> //required by output comparaison

// Install gtest  via these intructions: https://github.com/google/googletest/blob/master/googletest/README.md#generic-build-instructions
// Replace EXPECT by ASSERT if it doesn't make sense to continue when the assertion in question fails
// The syntax is TEST([GROUP], [TEST]) where you name your group of test and the specific test
// Don't include your main function as this file has its own
//compile via Makefile "tests_run" rule

TEST(BasicAssertions, Statement)
{
    bool statement = true;

    EXPECT_TRUE(statement); // statement
    EXPECT_FALSE(!statement); // !statement
}

TEST(BinaryComparison, Equality)
{
    int val1 = 42;
    int val2 = 42;
    int val3 = 84;

    EXPECT_EQ(val1, val2); // val1 == val2
    EXPECT_NE(val1, val3); // val1 != val3
}

TEST(BinaryComparison, GreaterLower)
{
    int val1 = 42;
    int val2 = 84;

    EXPECT_LT(val1, val2); // val1 < val2
    EXPECT_LE(val1, val2); // val1 <= val2
    EXPECT_GT(val2, val1); // val1 > val2
    EXPECT_GE(val1, val1); // val1 >= val2
}

TEST(StringComparison, String)
{
    EXPECT_STREQ("All of the birds", "All of the birds"); // same content case sensitive
    EXPECT_STRNE("died in 1986", "Died In 1986"); // different content case sensitive
    EXPECT_STRCASEEQ("due to REAGAN", "due to Reagan"); // same content
    EXPECT_STRCASENE("killing them", "and replacing them with spies"); // different content
}

TEST(COUTCOMP, CoutString)
{
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf()); //redirect std::cout to buffer

    std::cout << "ui" << std::endl; // output to std::cout

    std::cout.rdbuf(sbuf); //std::cout back to normal
    std::string expected = "ui\n"; // expected output

    EXPECT_EQ(buffer.str(), expected);
}

// I'll define an example function, but you can include your project's files to test your own
bool worksForTheBourgeoisie(const char *theBird) { return true; }

TEST(Example, ThatAreNowWatchingUs)
{
    EXPECT_TRUE(worksForTheBourgeoisie("Pigeon"));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

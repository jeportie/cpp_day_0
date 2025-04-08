/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_megaphone.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:00:33 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/01 15:52:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <string>
#include <cstdlib>
#include <cstdio>

std::string strToupper(std::string& str);
std::string strCheckSpace(std::string str);

// For stdout capture
std::string exec(const char* cmd)
{
    char        buffer[128];
    std::string result;
    FILE*       pipe = popen(cmd, "r");
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
        result += buffer;
    pclose(pipe);
    return result;
}

// Test strToupper
TEST(MegaphoneFunctions, StrToUpper)
{
    std::string input = "Hello 42!";
    EXPECT_EQ(strToupper(input), "HELLO 42!");
    std::string empty = "";
    EXPECT_EQ(strToupper(empty), "");
    std::string already_upper = "ALREADY UPPERCASE";
    EXPECT_EQ(strToupper(already_upper), "ALREADY UPPERCASE");
    std::string special_chars = "1234!@#$";
    EXPECT_EQ(strToupper(special_chars), "1234!@#$");
    std::string lowercase = "lowercase";
    EXPECT_EQ(strToupper(lowercase), "LOWERCASE");
}

// Test strCheckSpace
TEST(MegaphoneFunctions, StrCheckSpace)
{
    std::string input = "Hello     42!  Test   spaces!";
    EXPECT_EQ(strCheckSpace(input), "Hello 42! Test spaces!");
    EXPECT_EQ(strCheckSpace(std::string("")), "");
    EXPECT_EQ(strCheckSpace(std::string("NoExtraSpaces")), "NoExtraSpaces");
    EXPECT_EQ(strCheckSpace(std::string("  Leading and trailing spaces  ")), " Leading and trailing spaces ");
    EXPECT_EQ(strCheckSpace(std::string("     ")), " ");
}

// Test stdout behavior of the executable
TEST(MegaphoneIntegration, StdOutput)
{
    std::string result;

    result = exec("bin/megaphone \"shhhhh... I think the students are asleep...\"");
    EXPECT_EQ(result, "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\n");
    result = exec("bin/megaphone Damnit \" ! \" \"Sorry students, I thought this thing was off.\"");
    EXPECT_EQ(result, "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\n");
    result = exec("bin/megaphone");
    EXPECT_EQ(result, "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
    result = exec("bin/megaphone \"Hello      world      42     students!\"");
    EXPECT_EQ(result, "HELLO WORLD 42 STUDENTS!\n");
}

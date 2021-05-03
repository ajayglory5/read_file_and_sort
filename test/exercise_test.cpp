#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "src/compute_score.h"

using ::testing::internal::CaptureStderr;
using ::testing::internal::CaptureStdout;
using ::testing::internal::GetCapturedStderr;
using ::testing::internal::GetCapturedStdout;

std::string convertToLower(std::string const& instring)
{
    std::string outstring{instring};
    std::for_each(outstring.begin(), outstring.end(),
                  [](char& c) { c = ::tolower(c); });

    return outstring;
}

TEST(fileRead, expectError){
    CaptureStdout();

    std::vector<std::string> names;
    EXPECT_EQ(names.size(), 0);

    read_file("Invalid_file.txt", names);

    EXPECT_EQ(names.size(), 0);
    EXPECT_THAT(convertToLower(GetCapturedStdout()),
        ::testing::HasSubstr(convertToLower("Error in opening")));
} 

TEST(fileRead, expectSuccess){
    CaptureStdout();

    std::vector<std::string> names;
    EXPECT_EQ(names.size(), 0);

    char path[100];
    read_file("../test/test_data_1.txt", names);

    std::string logs = GetCapturedStdout();
    EXPECT_THAT(convertToLower(logs),
        Not(::testing::HasSubstr(convertToLower("Error in opening"))));
    EXPECT_THAT(convertToLower(logs),
        ::testing::HasSubstr(convertToLower("Started to parse")));
    EXPECT_EQ(names.size(), 3);
} 

TEST(sortNames, result){
    CaptureStdout();

    std::vector<std::string> names{"MARY","PATRICIA","LINDA"};
    std::vector<std::string> expected{"LINDA","MARY","PATRICIA"};
    sort_file(names);

    int i{0}; 
    for(auto &name: names){
        EXPECT_STREQ(names[i].c_str(), expected[i].c_str());
        i++;
    }
    GetCapturedStdout();
} 

TEST(scoreCalculation, name){
    CaptureStdout();
    std::vector<std::string> names;

    read_file("../test/test_data_1.txt", names);
    sort_file(names);

    EXPECT_EQ(obtain_name_score(names[0]), 40); 
    EXPECT_EQ(obtain_name_score(names[1]), 57);
    EXPECT_EQ(obtain_name_score(names[2]), 77);

    GetCapturedStdout();
}

TEST(totalScoreCalculation, test_data_1){
    CaptureStdout();
    std::vector<std::string> names;

    read_file("../test/test_data_1.txt", names);
    sort_file(names);
    EXPECT_EQ(find_total_score(names), 385);

    GetCapturedStdout();
}

TEST(totalScoreCalculation, names){
    CaptureStdout();
    std::vector<std::string> names;

    read_file("../src/names.txt", names);
    sort_file(names);
    EXPECT_EQ(find_total_score(names), 871198282);

    GetCapturedStdout();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

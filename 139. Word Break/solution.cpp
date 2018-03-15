//
// Created by fevemania on 3/15/18.
//
#include <gmock/gmock.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using testing::Eq;

// Assume there are k elements in wordDict
// Time: O(k)
// Space: O(1): not use any externel space.

// 1st word -> 0-4 4-8 => 0-8
// 2nd word -> 8-9
// .. => compare lowerbound and uppperbound

bool wordBreak(string s, vector<string>& wordDict) {
  size_t lowerbound = string::npos, upperbound = string::npos;
  for (auto const& word: wordDict) {
    size_t curr_lowerbound = s.find(word);
    while (curr_lowerbound != string::npos) {
      size_t curr_upperbound = curr_lowerbound + word.size();

      if (lowerbound == string::npos) {
        lowerbound = curr_lowerbound;
        upperbound = curr_upperbound;
      }
      else {
        if (curr_lowerbound <= upperbound) {
          upperbound = max(curr_upperbound, upperbound);
        }
        lowerbound = min(curr_lowerbound, lowerbound);
      }
      auto check_pos = s.rfind(word);
      if (check_pos != string::npos && check_pos <= upperbound && check_pos + word.size() == s.size()) {
        upperbound = s.size();
      }

      curr_lowerbound = s.find(word, curr_upperbound);
    }
  }
  return (lowerbound == 0UL) && (upperbound == s.size());
}

TEST(WordBreak, FoundsWords) {
  vector<string> dict {"leet", "code"};
  EXPECT_THAT(wordBreak("leet", dict), Eq(true));
  EXPECT_THAT(wordBreak("code", dict), Eq(true));
  EXPECT_THAT(wordBreak("leetcode", dict), Eq(true));
}

TEST(WordBreak, FoundsSameWords) {
  vector<string> dict {"leet"};
  ASSERT_THAT(wordBreak("leetleet", dict), Eq(true));
}

TEST(WordBreak, TacklesOverlappingWords) {
  vector<string> dict {"car", "ca", "rs"};
  ASSERT_THAT(wordBreak("cars", dict), Eq(true));
}

// Can't pass the Speical Case!!!
TEST(WordBreak, OnlyHasOneAlphabetInEachWord) {
  vector<string> dict {"aaaa", "aa"};
  ASSERT_THAT(wordBreak("aaaaaaa", dict), Eq(false));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}

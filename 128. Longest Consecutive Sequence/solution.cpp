//
// Created by sua on 3/14/18.
//

#include <gmock/gmock.h>
#include <vector>
using namespace std;
using testing::Eq;

int longestConsecutive(vector<int>& nums) {
  if (nums.empty()) return 0;

  std::sort(nums.begin(), nums.end());  // O(n log n)

  int cnt = 1, max_cnt = 1;

  for (int i = 1; i != nums.size(); ++i) {  // O(n)
    if (nums[i-1] + 1 == nums[i]) ++cnt;
    else if (nums[i-1] == nums[i]) ;
    else {
      max_cnt = std::max(cnt, max_cnt);
      cnt = 1;
    }
  }
  // If the last elem is still consecutive and the sequence is longest, update max_cnt
  return std::max(cnt, max_cnt);
}

TEST(LongestConsecutive, ReturnsZeroWhenNoElem) {
  vector<int> v;
  ASSERT_THAT(longestConsecutive(v), Eq(0));
}

TEST(LongestConsecutive, ReturnsTwoWhenTwoElemIsConsecutive) {
  vector<int> v {0, -1};
  ASSERT_THAT(longestConsecutive(v), Eq(2));
}

TEST(LongestConsecutive, FindsMaxCntWithoutDuplicateNumber) {
  vector<int> v {100, 4, 200, 3, 1, 2};
  ASSERT_THAT(longestConsecutive(v), Eq(4));  // [1,2,3,4]
}

TEST(LongestConsecutive, FindMaxCntWithDuplicateNumber) {
  vector<int> v {0, 2, 1, 1};
  ASSERT_THAT(longestConsecutive(v), Eq(3));
}

int main(int argc, char** argv)
{
  testing::InitGoogleMock(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}
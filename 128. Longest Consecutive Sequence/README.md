# Analysis (C++)

Though the problem ask for
the solution of O(n) time complexity.

I could just come up with Time O(n log n), Space O(1).

### My Solution:

First, `sort the given vector` in ascending order, which consume O(n log n).

Then, `traverse all the elem in`, which is O(n), to get the
longest subconsequence number. For each elem, I check it with the
previous one to predicate if it's still consecutive. If yes, update cnt.
If no, update max_cnt. Watch out for the elem that is the same as
previous one. If it's the case, don't update cnt.

`Note: ` About test case, I provided in solution.cpp.

### LeetCodo's Best Solution: Use HashSet to get Time O(n), Space O(n).
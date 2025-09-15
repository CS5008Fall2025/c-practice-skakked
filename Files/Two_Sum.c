/**
 * Two Sum
 * Solved
 * Easy
 * Topics
 * premium lock icon
 * Companies
 * Hint
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example 1:
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * Example 2:
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * Example 3:
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 *
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the result (2 integers)
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Check all pairs
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;  // Set the return size
                return result;
            }
        }
    }
    *returnSize = 0;
    free(result);
    return NULL;
}

/**
 * /* What I learned: I used a simple double loop to check every pair, starting j at i+1 so I don’t reuse the same element. 
 * As soon as I find a match, I return the two indices. 
 * In C, I must malloc the result, set *returnSize to 2 on success, and remember the caller will free it; if nothing is found, set *returnSize = 0, free the buffer, and return NULL. 
 * We return indices, not values, so sorting would lose positions unless we track them. A hash map could make it O(n), but in C that adds a lot of code and memory handling, 
 * so the brute-force version is fine for small to medium inputs and easy to get right. 
 * I comapred my solution to the leetcode solution and I think some solutions were faster but used more memory, and some were slower but used less memory.
 * The brute-force solution is O(n^2) time and O(1) space, while a hash map solution would be O(n) time and O(n) space.
 */
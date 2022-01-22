// Given an array, rotate the array to the right by k steps, where k is non-negative.
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k = k % nums.size();
        int next_number_to_move = nums[0];
        int current_position = 0;
        int target_position = 0;
        int start = 0;
        
        if (nums.size() == 1 || k == 0)
            return;
        
        for (int i = 0; i < nums.size(); i++) {
            target_position = (current_position + k) % nums.size();
            
            int temp = next_number_to_move;
            if (target_position != start) {
                next_number_to_move = nums[target_position];
            }
            else {
                next_number_to_move = nums[target_position+1];
            }
            nums[target_position] = temp;
            
            current_position = target_position;
            
            if (current_position == start && start <= (nums.size() - 1)) {
                current_position++;
                start++;
            }
            
        }
        
    }
};
#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n = nums.size();
        int window_size = 2 * k + 1;
        std::vector<int> avgs(n, -1); 

      
        if (n < window_size) {
            return avgs;
        }

        
        int* left = &nums[0];
        int* right = &nums[0];
        
        long long current_window_sum = 0;

        
        for (int i = 0; i < window_size; ++i) {
            current_window_sum += *right;
            right++; 
        }

       
        avgs[k] = current_window_sum / window_size;

       
        for (int i = k + 1; i < n - k; ++i) {
            current_window_sum -= *left; 
            left++;                      

            current_window_sum += *right;
            right++;                     

            avgs[i] = current_window_sum / window_size; 
        }

        return avgs;
    }
};

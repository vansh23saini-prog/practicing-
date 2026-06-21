
class Solution {
public:
    int numComponents(ListNode* head, std::vector<int>& nums) {
      
        std::unordered_set<int> setNums(nums.begin(), nums.end());
        int ans = 0;
        
        while (head != nullptr) {
        
            if (setNums.count(head->val)) {

                ans++;
              
                while (head != nullptr && setNums.count(head->val)) {
                    head = head->next;
                }
            } else {
               
                head = head->next;
            }
        }
        return ans;
    }
};

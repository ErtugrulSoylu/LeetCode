class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        int product = nums[0], res = 0;
        int j = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == j) {
                j = i + 1;
                product = nums[i];
            }
            for (; product < k && j < nums.size(); j++) {
                if (product * nums[j] >= k) {
                    res += j - i;
                    break ;
                }
                product *= nums[j];
                if (j == nums.size() - 1) {
                    res += (j - i + 1)*(j - i + 2)/2;
                    return res;
                }
            }
            product /= nums[i];
        }
        return res + (nums.back() < k);
    }
};
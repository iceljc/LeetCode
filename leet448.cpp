#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        for (int i=0; i<n; ++i) {
            int k = abs(nums[i]) - 1;
            cout << k << " " << endl;
            nums[k] = nums[k] > 0 ? -nums[k] : nums[k];
        }
        
        
        for (int i=0; i<n; ++i) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        
        return res;
        
        
    }
};


int main() {
	Solution sol;
	vector<int> nums;
	vector<int> res;

	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);


	res = sol.findDisappearedNumbers(nums); 

	for (int i=0; i<res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;

}







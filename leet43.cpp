#include<iostream>
#include<string>
#include<vector>
#include<typeinfo>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m+n);
        string ans = "";
        
        for(int i = m-1; i>=0; --i){
            for(int j = n-1; j>=0; --j){
                int ind1 = i + j;
                int ind2 = i + j + 1;
                int sum = (num1[i]-'0')*(num2[j]-'0') + res[ind2];
                res[ind1] += sum / 10;
                res[ind2] = sum % 10;
            }
        }
        
        for(auto a:res){
            if (ans.size() !=0 || a != 0)
                ans += to_string(a);
        }
        
        return ans.size() == 0 ? "0" : ans;
        
        
    }
};


int main(){

	string a = "123";
	string b = "456";
	
	Solution sol;
	string ans = sol.multiply(a, b);
	
    cout << ans << endl;
	
    
    return 0;

}

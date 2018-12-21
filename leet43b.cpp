#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <math.h>
using namespace std;


class Solution {
    public:
    long int power(int x, int n){
        long int val = 1;
        while(n--){
            val *= x;
        }
        return val;
    }
    
    
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<long int> res;
        string ans = "";
        
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                long int mult = (num1[i]-'0')*(num2[j]-'0');
                int index = (m-i-1)+(n-j-1);
                mult = mult * power(10, index);
                res.push_back(mult);
            }
        }
        
        long int val = 0;
        for(auto a:res){
            val += a;
        }
        
        ans = to_string(val);
        
        return ans;
        
        
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


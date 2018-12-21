#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void helper(vector<string>& res, string s, int i0, int j0, char p1, char p2) {
        int p = 0;
        for(int i = i0; i < s.length(); ++i) {
            if(s[i] == p1) ++p;
            if(s[i] == p2) --p;
            if(p >= 0) continue;
            for(int j = j0; j <= i; ++j) {
                if(s[j] == p2 && (j == j0 || s[j-1] != p2))
                    helper(res, s.substr(0,j)+s.substr(j+1), i, j, p1, p2);
                	for (int k=0; k<res.size(); ++k){
                		cout << res[k];
                	}
                	cout << endl;

            }
            return;
        }
        reverse(s.begin(), s.end());
        if(p1 == '(') helper(res, s, 0, 0, ')', '(');
        else res.push_back(s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(res, s, 0, 0, '(', ')');
        return res;
    }
};


int main(){
	string s = "((()";
	vector<string> res;
	Solution sol;
	res = sol.removeInvalidParentheses(s);

	for (int i=0; i<res.size(); ++i){
		cout << res[i];
	}

	cout << endl;




}

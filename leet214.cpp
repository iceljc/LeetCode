#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public: 
	string shortestPalindrome(string s)
	{
    	int n = s.size();
    	string rev(s);
    	reverse(rev.begin(), rev.end());
    	string s_new = s + "#" + rev;
    	int n_new = s_new.size();
    	vector<int> f(n_new, 0);

    	for (int i = 1; i < n_new; i++) {
        	int t = f[i - 1];

        	while (t > 0 && s_new[i] != s_new[t])
            	t = f[t - 1];

        	if (s_new[i] == s_new[t])
            	++t;
            
        	f[i] = t;
        	cout << f[i] << endl;
    	}
    	return rev + s.substr(f[n_new - 1]);
    	//return rev.substr(0, n - f[n_new - 1]) + s;
	}


};


int main(){
	string s = "abbaa";
	Solution sol;
	string res = sol.shortestPalindrome(s);

	for (int i=0; i<res.size(); ++i){
		cout << res[i];
	}
	cout << endl;
}






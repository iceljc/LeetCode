#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        unordered_map<char, int> myMap;
        int maxsublen = 0;
        int i,j=0;
        for (i=0; i<s.size(); ++i){
        	if (myMap.count(s[i])>0){
        		j = max(j, myMap[s[i]]+1);
        	}
        	myMap[s[i]] = i;
        	maxsublen = max(maxsublen, i-j+1);
        }

        return maxsublen;

    }
};


int main() {
	string s = "abcabca";
	Solution sol;

	int res;
	res = sol.lengthOfLongestSubstring(s);

	cout << res << endl;
	return 0;

}
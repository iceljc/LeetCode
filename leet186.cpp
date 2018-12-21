#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s){
		if (s.size()==0)
			return;

		int i = 0, right = 0, length = s.size();
		while (i < length){
			while (right < length && s[right] != ' '){
				right ++;
			}
			reverse(s.begin()+i, s.begin()+right);
			for(int i=0; i<s.size(); ++i){
				cout << s[i];
			}
			cout << endl;
			i = ++right;
		}
		reverse(s.begin(), s.end());

	}

};



int main() {
	string s = "the sky is blue";
	Solution sol;
	sol.reverseWords(s);

	for(int i=0; i<s.size(); ++i){
		cout << s[i];
	}
	cout << endl;

}



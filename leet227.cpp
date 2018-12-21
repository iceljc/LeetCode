#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public: int calculate(string s) {
    if (s.size() == 0) {
        return 0;
    }

    int num = 0, res = 0, top = 0;
    char op = '+';
    stack<int> mystk;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + c - '0';
        }

        if ((i == s.size() - 1) || (!isdigit(c) && c != ' ')) {
            if (op == '+') {
                mystk.push(num);
            } else if (op == '-') {
                mystk.push(-num);
            } else if (op == '*') {
            	top = mystk.top() * num;
            	mystk.pop();
                mystk.push(top);
            } else if (op == '/') {
            	top = mystk.top() / num;
            	mystk.pop();
                mystk.push(top);
            }
            op = c;
            num = 0;
        }
    }
    
    while (!mystk.empty()) {
        res += mystk.top();
        mystk.pop();
    }

    return res;
	}
};


int main(){
	string s = "3+2*2";
	Solution sol;
	int res = sol.calculate(s);

	cout << res << endl;
}





#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> res;
        unordered_map<string, int> Map;
        unordered_map<string, int> temp;
        
        int slen = s.size();
        int wlen = words.size();        
        
        if (slen == 0 || wlen == 0){
            return res;
        }
        
        int perlen = words[0].size();
        
        if (wlen*perlen > slen){
            return res;
        }
        
        for (int i=0; i<wlen; ++i){
            Map[words[i]]++;
        }
        

        for (int i=0; i+perlen*wlen-1<slen; ++i){
            int j = i;
            temp.clear();
            
            while (j <= i+wlen*perlen - 1){
                string cur_sub = s.substr(j, perlen); // current substring
                temp[cur_sub]++;
                if (Map[cur_sub] < temp[cur_sub]){
                    break;
                }
                else{
                    j += perlen;
                }
                
                if (j>i + wlen*perlen - 1){
                    res.push_back(i);
                }
            }
        }
        
        return res;
    }
    
};




int main(){
    
    string s = "barfoothefoobarman";
    //string s = "foothebarbarfooman";
    vector<string> words;
    words.push_back("bar");
    words.push_back("foo");
    
    Solution sol;
    
    vector<int> res = sol.findSubstring(s, words);
    
    for (int i = 0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
    
}

class Solution {
public:
    string sortSentence(string s) {
        int n = s.length();
        string word;
        vector<string>v(10);
        for(int i=0; i<n; i++){
            if(s[i]>=48 && s[i]<=57){
                v[s[i]-48] = word + " ";
                word = "";
                i++;
            }
            else
                word += s[i];
        }
        
        string ans;
        for(string x:v){
            ans += x;
        }
        int t = ans.length();
        return ans.substr(0,t-1);
    }
};
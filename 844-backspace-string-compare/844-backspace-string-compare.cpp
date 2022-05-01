class Solution {
public:
    string endString(string s){
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            st.push(s[i]);
            if(st.top() == '#'){
                if(st.size()>0)
                    st.pop();
                if(st.size()>0)
                    st.pop();
            }
        }
        string p="";
        while(!st.empty()){
            char c = st.top();
            p.push_back(c);
            st.pop();
        }
        return p;
    }
    
    bool backspaceCompare(string s, string t) {
       return endString(s) == endString(t);
    }
};
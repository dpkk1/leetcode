class Solution {
public:
    vector<int> pancakeSort(vector<int>& v) {
        int  n = v.size();
        vector<int>res;
        int end = v.size();
        while(end != 1){
            int index = find(v, end);
            flip(v, index);
            flip(v, end-1);
            res.push_back(index+1);
            res.push_back(end);
            end--;
        }
        return res;
    }
    
    int find(vector<int>&v, int tar){
        for(int i=0; i<v.size(); i++){
            if(v[i]==tar)
                return i;
        }
        return -1;
    }
    
    void flip(vector<int>&v, int k){
        int i=0;
        while(i<k){
            int temp = v[i];
            v[i] = v[k];
            v[k] = temp;
            i++;
            k--;
        }
    }
};
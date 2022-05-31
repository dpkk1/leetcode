class Solution {
public:
    int climbStairs(int n) {
        map<int, int>m;
        return totalWays(0, n, m);
    }
    
    int totalWays(int currentStair, int targetStair, map<int, int>&m){
        if(currentStair == targetStair)
            return 1;
        if(currentStair > targetStair)
            return 0;
        int currentKey = currentStair;
        if(m.find(currentKey) != m.end())
            return m[currentKey];
        int oneJump = totalWays(currentStair+1, targetStair, m);
        int twoJump = totalWays(currentStair+2, targetStair, m);
        m[currentKey] = (oneJump + twoJump);
        return (oneJump+twoJump);
    }
};
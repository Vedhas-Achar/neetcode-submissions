class Solution {
public:

    int climbStairs(int n) {
        vector<int> fib;
        fib.push_back(0);
        fib.push_back(1);

        int i;
        for(i = 2; i <= n+1; i++){
            fib.push_back(fib[i-1] + fib[i-2]);
        }

        return fib[n+1];

    }
};

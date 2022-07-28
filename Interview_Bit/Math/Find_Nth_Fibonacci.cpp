const int MAX = 1000000005;
 
// Create an array for memoization
int f[MAX] = {0};
 
int Solution::solve(int n) {
	   if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);
 
    // If fib(n) is already computed
    if (f[n])
        return f[n];
 
    int k = (n & 1)? (n+1)/2 : n/2;
 
    // Applying above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1)? ((solve(k)*solve(k))%1000000007 + (solve(k-1)*solve(k-1))%1000000007)
           : (2*solve(k-1)%1000000007 + (solve(k))*solve(k))%1000000007;
 
    return f[n]%1000000007;
}


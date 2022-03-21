// TIMe complexity=O(N)
// space complexity=O(1)
int Solution::solve(string A) {
    int l=0;int n=A.length();
    int r=n-1;int ans=0;
    while(l<=r){
        if(A[l]!=A[r]){   // if dont get same char then again start  l from 0 (as inserting from beginning )and r from present index
            if(l==0)
                r--;
            else
                l=0;
            ans=n-r-1;
        }
        else{
            r--;
            l++;
        }
    }
    return ans;

}

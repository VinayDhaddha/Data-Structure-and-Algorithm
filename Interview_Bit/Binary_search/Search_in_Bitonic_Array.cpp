// time complexity=O(logN)
// space complexity=O(logN)
int binary_s(vector<int> &A,int l,int r,int B,int ans){  // customize binary search
    if(l<=r){
        int mid=l+floor((r-l)/2);           
        if(A[mid]==B)               // if we get element then return index mid
            return mid; 
        if(ans==-1)                 // if ans==-1 means till now we not get that element then search for it in right half
            ans=binary_s(A,mid+1,r,B,ans);
        if(ans==-1)                 // if ans==-1 means till now we not get that element then search for it in left half
            ans=binary_s(A,l,mid-1,B,ans);
        return ans;             // return ans
    }
    else
        return -1;              // else not found(-1)
}
int Solution::solve(vector<int> &A, int B) {
    // int r1=0,r2=0;
    int ans=-1;
    ans=binary_s(A,0,A.size()-1,B,ans);         // lets begin our binary search
    return ans;
    //return 0;
}

int Solution::nTriang(vector<int> &A) {
    if(A.size()<3)
        return 0;
    long long int  i=0,start,end,count=0;
    sort(A.begin(),A.end());
    for(i=A.size()-1;i>1;i--){
        start=0;
        end=i-1;
        if(A[i]==0)
            continue;
        while(start<end){
            long long int sum=(long long int)A[start]+(long long int)A[end];
            if((sum)>A[i]){
                count+=end-start;
                // printf("%d  %d %d\n",i,start,end);
                end--;
            }
            else{
                start++;
            }
        }
    }
    return count;
}


// sliding window concept

int Solution::solve(vector<int> &A, int B) {
    int count=B,i=0,l=0,max=-1,lft=0;
    for(i=0;i<A.size();i++){
        if(A[i]==0){
            if(count>0){
                l++;
                count--;
            }
            else{
                if(max<l){
                    // printf("i=%d\n",i);
                    max=l;
                }
                while(A[lft]!=0){
                    l--;
                    lft++;
                }
                // i=lft;
                lft++;
                // count++;
            }
        }
        else{
            l++;
        }
    }
    if(max<l){
        // printf("i1=%d\n",A[i]);
        max=l;
    }
    return max;

    
}



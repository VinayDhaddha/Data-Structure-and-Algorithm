// Time complexity: O(n)
//   Space complexity: O(1)
vector<int> Solution::maxone(vector<int> &A, int B) {
    vector<int> ans;
    int start=0,end=0,count=B,max=INT_MIN,index;
    if(A.size()<=1)
        return ans;
    else{
        while((start<=end)&&(end<(A.size()))){
            if((A[end]==0)&&(count>0)){
                end++;
                count--;
            }
            else if(A[end]==1){
                end++;
            }
            else{
                // if(e>0){
                //     e=e-1;
                // }
                if(max<(end-start)){
                    max=end-start;
                    index=start;
                }
                while(A[start]!=0){
                    start++;
                }
                start++;
                end++;
            }
        }
    }
    // printf("$$$$$start=%d  end=%d\n",start,end);
    if(max<(end-start)){
        max=end-start;
        index=start;
    }
    for(int i=index;i<(index+max);i++){
        ans.push_back(i);
    }
    return ans;
}


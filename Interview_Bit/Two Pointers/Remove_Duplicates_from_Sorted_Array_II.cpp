int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int j=1,flag=0,count=-1;
    for(;j<A.size();){
        if(A[j]==A[j-1]){
            if(flag==0){
                flag=1;
                if(count!=-1){
                    A[count++]=A[j];
                }
            }
            else{
                // if(count!=-1){
                //     A[count++]=A[j];
                // }
                if(count==-1){
                    count=j;
                }
            }
            j++;
        }
        else{
            if(flag==1)
                flag=0;
            if(count!=-1){
                A[count++]=A[j];
            }
            j++;
        }
    }
    if(count!=-1){
        for(j=A.size()-1;j>=count;j--){
            A.pop_back();
        }
    }
    else{
        count=A.size();
    }
    return count;
}


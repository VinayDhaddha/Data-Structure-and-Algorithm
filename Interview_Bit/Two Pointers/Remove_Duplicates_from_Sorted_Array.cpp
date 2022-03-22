int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0,j=i+1,count=-1;
    for(;j<A.size();j++){
        if(A[j]==A[i]){
            if(count==-1)
                count=j;
        }
        else{
            if(count>-1){
                A[count++]=A[j];
            }
        }
        i=j;
    }
    if(count==-1)
        count=j;
    return count;
}


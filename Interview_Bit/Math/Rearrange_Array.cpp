//important to watch editorial solution tooo
void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int arr[300000]={0};
    for(int i=0;i<A.size();i++){
        arr[i]=A[i];
    }
    for(int i=0;i<A.size();i++){
        A[i]=arr[A[i]];
    }
    return ;
}


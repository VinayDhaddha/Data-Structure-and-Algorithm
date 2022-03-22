void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> c;
    int i=0,j=0;
    while((i<A.size())&&(j<B.size())){
        if(A[i]<B[j])
            c.push_back(A[i++]);
        else
            c.push_back(B[j++]);
    }
    if(i==A.size()){
        while(j<B.size()){
            c.push_back(B[j++]);
        }
    }
    else{
        while(i<A.size()){
            c.push_back(A[i++]);
        }        
    }
    A=c;
    return ;
}


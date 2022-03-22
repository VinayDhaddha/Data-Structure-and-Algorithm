// time complexity O(A.size()+B.size()+C.size())
// space complexity O(1)
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int m1,m2,m3,i=0,j=0,k=0,maxm=0,min=INT_MAX;
    int *ptr;
    while((i<A.size())&&(j<B.size())&&(k<C.size())){
        m1=A[i]-B[j];       //
        m2=B[j]-C[k];       //  finding difference with sign of magnitude
        m3=C[k]-A[i];       //  magnitude helps to find which is greater outof 2
        maxm=max(max(abs(A[i] - B[j]), abs(B[j] - C[k])), abs(C[k] - A[i]));// max fxn 2 arg at a time
        if(maxm==abs(m1)){  // decreasing max(m1,m2.m3) so that we can get min out of max of m1,m2,m3
            if(m1<0)
                ptr=&i; // it helps to know out of which iterator(i.e i,j,k) which we have to increment
            else
                ptr=&j;
            
        }
        else if(maxm==abs(m2)){
            if(m2<0)
                ptr=&j;
            else
                ptr=&k;            
        }
        else{
            if(m3<0)
                ptr=&k;
            else
                ptr=&i;            
        }
        if(min>maxm)    // assigning minimum out of max(m1,m2,m3)
            min=maxm;
        (*ptr)++;       // incrementing in the iterator which s giving abs(maximum difference)
    
                        //for ex. abs(A[i]-A[j])  is max if   (A[i]-A[j]) < 0 , then i++
    }                   //                               else       j++;    
    return min;
    
    
}

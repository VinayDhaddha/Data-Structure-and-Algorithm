int Solution::diffPossible(vector<int> &A, int B) {
    int i=0,j=i+1;
    for(;(j>i)&&(j<A.size());){
        if((A[j]-A[i])==B)
            return 1;
        else if((A[j]-A[i])>B){
            // if((A[j-1]-A[i])>=B)
            //     j--;
            // else if((A[j]-A[i+1])>=B)
            //     i++;
            // else{
            //     // i++;
            //     j++;
            // }
            i++;
            if(i==j)
                j++;
        }
        else{
            j++;
        }
            
    }
    return 0;
}


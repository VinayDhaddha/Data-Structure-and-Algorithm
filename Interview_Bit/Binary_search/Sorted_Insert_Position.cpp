// time complexity=O(logN)
// space complexity=O(logN)
int binary_search(vector<int> &A,int l,int r,int B){ // binary_search program
    if(l<=r){
        int mid=l+floor((r-l)/2);
        if(A[mid]==B)
            return mid;
        else if(A[mid]>B){
            return binary_search(A,l,mid-1,B);
        }
        else{
            return binary_search(A,mid+1,r,B);
        }
    }
    else 
        return l;           // returning l to give the index where we have to insert element when B not found
}
int Solution::searchInsert(vector<int> &A, int B) {
    int size=A.size();
    int i=binary_search(A,0,size-1,B);
    if(A[i]==B)
        return i;
    else if(A[i]<B){                // condn if A[i] <B 
       // printf("-------yes------%d   %d\n",i,A[i]);
        return i+1;
    }
    else{
        if(i==0)        // condn if i ==0  
            return 0;
        else{
          // printf("-------yes------%d   %d\n",i,A[i]);
            return i;
        }
    }
}

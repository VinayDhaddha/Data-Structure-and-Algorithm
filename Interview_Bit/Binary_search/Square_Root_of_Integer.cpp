// time complexity=O(logN)
// space complexity=O(1)
long long int binary_search(long long int l,long long int r,long long int A){   // binary search concept
    if(l<r){
        long long int mid=l+floor((r-l)/2);
        if((mid*mid)==A)
            return mid;
        else if((mid*mid)<A){
           //  printf("$$$$111111$$ %d $$$$$\n",mid);
            return binary_search(mid+1,r,A);
        }
        else{
            //printf("$$$2222222$$$ %d $$$$$\n",mid);
            return binary_search(l,mid-1,A);
        }
    }
    else 
        return l;               // returning l to give floor value 
}
int Solution::sqrt(int A) {
    long long int num;
    num=binary_search(1,floor(A/2),A);
    if(num*num >A)                      // condition must be check
        return num-1;
    else 
        return num;
    
}


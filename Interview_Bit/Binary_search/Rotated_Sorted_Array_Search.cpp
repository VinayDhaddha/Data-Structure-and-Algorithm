int top(const vector<int> &A,int l,int r,int B){
    int a,b;
    if(l<r){
        int mid=l+floor((r-l)/2);
        if(mid!=0){
            if((A[mid+1]>A[mid])&&(A[mid-1]>A[mid]))
                return mid;
        }
        if(A[mid]>A[r])
            return top(A,mid+1,r,B);
        else if(A[mid]<A[r])
            return top(A,l,mid-1,B);
        // else{
        //     a=top(A,mid+1,r,B);
        //     b=top(A,l,mid,B);
        //     a=A[a]>A[b]?a:b;
        //     return a;
        // }
    }
    return l;
}
int binary_a(const vector<int> &A,int l,int r,int B){
    if(l<r){
        int mid=l+floor((r-l)/2);
        if(A[mid]==B)
            return mid;
        else if(A[mid]>B)
            return binary_a(A,l,mid-1,B);
        else
            return binary_a(A,mid+1,r,B);
    }
    return l;
}
int binary_d(const vector<int> &A,int l,int r,int B){
    if(l<r){
        int mid=l+floor((r-l)/2);
        if(A[mid]==B)
            return mid;
        else if(A[mid]<B)
            return binary_d(A,l,mid-1,B);
        else
            return binary_d(A,mid+1,r,B);
    }
    return l;
}
int Solution::search(const vector<int> &A, int B) {
    int r1=0,r2=0;
    int middle=top(A,0,A.size()-1,B);
    if(middle==0){
        r1=binary_a(A,0,A.size()-1,B);
        if(A[r1]==B)
            return r1;
        else 
            return -1;
    }
    else{
        if((A[0]<=B)&&(A[middle-1]>=B))
            r1=binary_a(A,0,middle-1,B);
        if((A[middle]<=B)&&(A[A.size()-1]>=B)) {
         //    printf("$$$$$$$$\n");
            r2=binary_a(A,middle,A.size()-1,B);
            // printf("$$$$%d$$$$\n",r2);
        }
        // printf("$$$$%d$$$$$$$$$\n",middle);
        if(A[r1]==B)
            return r1;
        else if(A[r2]==B)
            return r2;
        else
            return -1;
    }
}


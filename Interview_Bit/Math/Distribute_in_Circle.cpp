int Solution::solve(int A, int B, int C) {
    int temp=(C-1+A)%B;
    if(temp==0){
        temp=B;
    }
    return temp;
}


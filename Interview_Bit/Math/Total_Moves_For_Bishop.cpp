int min(int a,int b){
    if(a>=b)
        return b;
    else
        return a;
}
int Solution::solve(int A, int B) {
    return (min(8-B,8-A)+min(8-B,A-1)+min(A-1,B-1)+min(B-1,8-A));
    // int x=A,y=B;
    //top left diagonal
}


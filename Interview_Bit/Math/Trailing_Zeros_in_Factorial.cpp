int Solution::trailingZeroes(int A) {
    int count=0;
    for(;A>0;){
        A=A-A%5;
        count+=A/5;
        A=A/5;
    }
    return count;
}

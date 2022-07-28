int Solution::titleToNumber(string A) {
    int num,i,count=0;
    for(i=0;i<A.size();i++){
        num=A[i]-'A'+1;
        count=count*26+num;
    }
    return count;
}


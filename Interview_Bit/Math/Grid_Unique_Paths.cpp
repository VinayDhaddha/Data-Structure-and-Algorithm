void finding(int A,int B,int i,int j,int &count){
    // cout<<"("<<i<<" "<<j<<") ";
    if((i>A)||(j>B)){
        // cout<<endl;
        return ;
    }
    if((i==A)&&(j==B)){
        // cout<<"   yes"<<endl;
        count++;
        return;
        // cout<<endl;
    }
    finding(A,B,i,j+1,count);
    finding(A,B,i+1,j,count);
    return ;

}
int Solution::uniquePaths(int A, int B) {
    int i=0,j=0,sum=0;
    if(A!=0){
        A-=1;
    }
    if(B!=0){
        B-=1;
    }
    finding(A,B,i,j,sum);
    return sum;
}


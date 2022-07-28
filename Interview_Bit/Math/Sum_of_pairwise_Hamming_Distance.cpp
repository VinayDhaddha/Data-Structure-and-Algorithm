int Solution::hammingDistance(const vector<int> &A) {
    vector<int> v(31,0);
    long long int sum=0,n=A.size();
    for(int i=0;i<A.size();i++){
        int k=30;
        while(k>=0){
            int num=1<<k;
            if((num & A[i])!=0){
                v[k]++;
                // sum++
            }
            k--;
        }
    }
    for(int i=0;i<31;i++){
        // cout<<v[i]<<endl;
        if(v[i]!=0)
            sum+=(n-v[i])*v[i];
        sum=sum%1000000007;
    }
    return (sum*2)%1000000007;
}


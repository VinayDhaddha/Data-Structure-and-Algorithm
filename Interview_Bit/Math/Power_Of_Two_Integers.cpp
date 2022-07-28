int Solution::isPower(int A) {
    if(A==1){
        return 1;
    }
    int temp=A,i;
   unordered_map<int,int> um;
    for(i=2;(i<=sqrt(A))&&(temp>1);){
        if((temp%i)==0){
            // cout<<"i="<<i<<endl;
            temp=temp/i;
            // s.insert(i);
            um[i]++;
        }
        else{
            if(um[i]%2!=0){
                return 0;
            }
            i++;
        }
    }
    // cout<<"size="<<um.size()<<endl;
    if((um.size()!=1)&&((um.size()==0)||(um[i]%2!=0))){
        return 0;
    }
    return 1;
}
// 

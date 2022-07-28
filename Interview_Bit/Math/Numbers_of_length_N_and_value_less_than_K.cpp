int Solution::solve(vector<int> &A, int B, int C) {
    if(A.size()==0){
        return 0;
    }
    int num=C,count=0,flag=0,ans=0;
    while(num!=0){
        num=num/10;
        count++;
    }
    if(count<B){
        return 0;
    }
    else if(count!=B){
        int multi=A.size();
        if(A[0]!=0){
            ans=pow(A.size(),B);
        }
        else{
            ans=(A.size()-1)*(pow(A.size(),B-1));
        }
        if((B==1)&&(A[0]==0)){
            ans++;
        }
        return ans;
    }
    else{
        if(B==1){
            for(int i=0;i<A.size();i++){
                if(A[i]<C)
                    ans++;
            }
        }
        else{
            vector<int> temp(B,0);
            count=0;
            for(int i=B-1;i>=0;i--){
                temp[i]=C%10;
                C=C/10;
            }
            for(int i=0;i<A.size();i++){
                // cout<<"i="<<i<<endl;
                if(A[i]==0)
                    continue;
                if(A[i]>temp[0]){
                    // cout<<"A[i]="<<A[i]<<"   temp[0]="<<temp[0]<<endl;
                    break;
                }
                else{
                    count++;
                }
            }
            // cout<<"count="<<count<<endl;
            ans=count*(pow(A.size(),B-1));
            // cout<<"ans="<<ans<<endl;
            int flag=0,j=0;
            for(int i=0;i<A.size();i++){
                if(A[i]==temp[j]){
                    flag=1;
                    break;
                }
            }
            j++;
            while((flag==1)&&(j<B)){
                flag=0;
                int countx=0;
                for(int i=0;i<A.size();i++){
                    if(A[i]>temp[j]){
                        countx++;
                    }
                    if(A[i]==temp[j]){
                        flag=1;
                    }
                }
                ans-=countx*(pow(A.size(),B-j-1));
                j++;
            }
            if((j==B)&&(flag==1)){
                ans--;
            }

        }
    }
    return ans;
}

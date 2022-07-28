#include<bits/stdc++.h>
string Solution::solve(string A) {
    int n=A.size()-1;
    multiset<char> ms;
    vector<int> v(10,0);
    unordered_map<string,int> um;
    int i=n,flag=0,j;
    while(i>=0){
        if(ms.empty()){
            v[A[i]-'0']++;
            ms.insert(A[i]);
            A.pop_back();
        }
        else{
            int temp=A[i]-'0';
            // cout<<"temp="<<temp<<endl;
            // flag=0;
            ms.insert(A[i]);
            v[temp]++;
            A.pop_back();
            // cout<<"----->A="<<A<<endl;
            for(j=(temp+1);j<10;j++){
                if(v[j]>0){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        // cout<<A<<"   i="<<ms.size()<<endl;
        i--;
    }
    if(flag==0){
        return "-1";
    } 
    else{
        A.push_back(j+'0');
        v[j]--;
        ms.erase(ms.find(j+'0'));
        string s1="";
        s1.assign(ms.begin(),ms.end());
        A=A+s1;
    }
    return A;
}



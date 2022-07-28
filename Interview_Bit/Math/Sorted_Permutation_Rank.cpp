// HINT:https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/

// *******************************************
// similar to 
// Sorted Permutation Rank 
// city tour
// ********************************************
#include<bits/stdc++.h>
int Solution::findRank(string A) {
    vector<int> fac(60,0);
    long long int ans=0;
    fac[0]=1;
    for(int i=1;i<60;i++){
        fac[i]=(i*fac[i-1])%1000003;
        // cout<<i<<endl;
    }
    set<char> s;
    for(int i=0;i<A.size();i++){
        // A[i]=toupper(A[i]);
        s.insert(A[i]);
        // cout<<
    } 
    for(int i=0;i<A.size();i++){
        auto it=s.find(A[i]);
        // auto it2=s;
        // cout<<A[i]<<"   distance="<<distance(s.begin(),it)<<endl;
        ans+=(distance(s.begin(),it)*fac[s.size()-1])%1000003;
        s.erase(it);
    } 
    ans+=1;
    return ans%1000003;
}


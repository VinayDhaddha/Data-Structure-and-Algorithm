#include<bits/stdc++.h>
int Solution::reverse(int A) {
    int m,temp=0,prev;
    while(A!=0){
        prev=temp;
        temp=temp*10+A%10;
        // cout<<((temp-A%10)/10)<<" "<< prev<<endl;
        if(((temp-A%10)/10)!=prev)
            return 0;
        A=A/10;
    }
    if(((temp-A%10)/10)!=prev)
        return 0;
    return temp;
    // temp=temp;
    // return temp;
    
}


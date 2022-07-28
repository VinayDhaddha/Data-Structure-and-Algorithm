#include<bits/stdc++.h>
string addition_in_string(string a,int num){
    string result;
    int i=a.size()-1,carry=0;
    int temp=a[i]-'0'+num;
    a.pop_back();
    if((temp/10)!=0){
        carry=temp/10;
    }
    temp=temp%10;
    result.push_back(temp+'0');
    i--;
    while((a.size()>0)&&(carry!=0)){
        temp=a[i]-'0'+carry;
        carry=temp/10;
        temp=temp%10;
        result.push_back(temp+'0');
        i--;
        a.pop_back();
    }
    if(carry!=0){
        result.push_back(carry+'0');
    }
    reverse(result.begin(),result.end());
    a=a+result;
    return a;
}
string Solution::solve(string A) {
    string ans;
    if(A.size()==1){
        int num=stoi(A);
        // cout<<num<<endl;
        if(num<9){
            num++;
            ans=to_string(num);
        }
        else{
            ans="11";
        }
        return ans;
    }
    else{
        int num;
        int n=A.size(),num_b;
        string l,r,a,b;
        if(n%2!=0){
            // cout<<"size of n="<<n<<endl;
            // int ind=
            l=A.substr(0,ceil(n/2.0));
            r=A.substr(floor(n/2.0),ceil(n/2.0));
            // cout<<"<---------------->"<<l<<"&&&&&&&&&&"<<r<<endl;
            a=l;
            reverse(l.begin(),l.end());
            // cout<<"reverse   a-->"<<l<<endl;
            string rev_a;
            rev_a=l;
            b=r;
            // cout<<"yes---------1>"<<endl;
            if(rev_a>b){
                ans=a;
                int t=a.size();
                l=a.substr(0,t-1);
                reverse(l.begin(),l.end());
                ans+=l;
            }
            else{
                int temp=a[a.size()-1]-'0';
                if(temp<9){
                    a=addition_in_string(a,1);
                    ans=a;
                    int t=a.size();
                    l=a.substr(0,t-1);
                    reverse(l.begin(),l.end());
                    ans+=l;
                }
                else{
                    int t1=a.size();
                    a=addition_in_string(a,1);
                    ans=a;
                    int t2=a.size();
                    if(t1==t2){
                        l=a.substr(0,t1-1);
                    }
                    else{
                        l=a.substr(0,t2-2);  
                    }
                    reverse(l.begin(),l.end());
                    ans+=l;
                }
            }
        }
        else{
            // cout<<"size of n-  even-------->"<<n<<endl;
            int ind=n/2-1;
            l=A.substr(0,n/2);
            r=A.substr(n/2,n/2);   
            // cout<<"l---------------->"<<l<<"&&&&&&&&&&"<<r<<endl;
            a=l;
            b=r;
            // cout<<"r---------"<<r<<endl;
            reverse(l.begin(),l.end());
            // cout<<"reverse of l------------>"<<l<<endl;
            string rev_a=l;
            if(b<rev_a){
                ans=a;
                ans+=rev_a;
                // cout<<"yes--------->"<<ans<<endl;
            }     
            else{
                // ----------------------------
                int temp=a[a.size()-1]-'0';
                if(temp<9){
                    a=addition_in_string(a,1);
                    ans=a;
                    l=a;
                    reverse(l.begin(),l.end());
                    ans+=l;
                }
                else{
                    int t1=a.size();
                    a=addition_in_string(a,1);
                    ans=a;
                    int t2=a.size();
                    if(t1==t2){
                        l=a;
                    }
                    else{
                        l=a.substr(0,t2-1);  
                    }
                    reverse(l.begin(),l.end());
                    ans+=l;
                }          
            }    
        }
    }
    return ans;
}


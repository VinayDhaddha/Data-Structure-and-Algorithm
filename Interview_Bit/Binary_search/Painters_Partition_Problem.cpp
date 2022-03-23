// same concept as book allotment
// time commplexity=O(NlogN)
// space commplexity=O(1)

#define mod 10000003
    
long long int count_time(vector<int> &C,long long int p){
    long long int i=0,sum=0,s=0;
    while(i<C.size()){
        if((sum+C[i])<=p){
            sum+=C[i];
            i++;
        }
        else{
            sum=0;
            s++;
        }
    }
    if(sum>0)
        s++;
    return s;
}
int Solution::paint(int A, int B, vector<int> &C) {

    long long int max=INT_MIN,i,sum=0,l,r,min_time,s;
    for(i=0;i<C.size();i++){
        C[i]=C[i];
        if(C[i]>max)
            max=C[i];
        sum+=C[i];
    }
    
    if(C.size()<A)
        return (max*B)%mod;
    l=max;
    r=sum;
    min_time=max;
    while(l<=r){
        int mid=l+floor((r-l)/2);
        s=count_time(C,mid);
        if(s<A){
            r=mid-1;
        }
        else if(s>A){
            l=mid+1;
        }
        else{
            min_time=mid;
            r=mid-1;
        }
    }
    return (min_time*B)%mod;
    
}
    


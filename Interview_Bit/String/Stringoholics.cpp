// time complexity=O(N^2)
// SPACE COMPLEXITY=O(N)
#define mod 1000000007
int Solution::solve(vector<string> &A) {
    int l = 1,len=A.size(),h;
    vector<int> v(len);
    for(int k=0;k<len;k++){             
            //  saving time interval t for each string
        int n = A[k].length(); 
        if(n<=1){ 
        v[k] = 1;
        }
        else{
            long long i=1,j=1,changes=0;
            string s = A[k];
            while(1){
                changes = (i*(i+1))/2;          // AP sum n*(n+1)/2
                if(changes%n==0){                   // if changes is multiple of n then store that and break the loop
                    v[k]=i;
                    break;
                }
                    i++;
            }
        }      
    }
    long long ans=1;
    for(int i=0;i<len;i++){                 // loop helps to remove the gcd present in v[j] with respect  to v[i]
        for(int j=i+1;j<len && v[i]!=1 ;j++){
            v[j] = v[j]/__gcd(v[j],v[i]);               // removing greastest common devision if present
        }
        ans = (long long int)(ans%mod*(v[i])%mod)%mod;             // storing ans=ans*v[i]   as v[i] has done there work(also takking care of modulus)
    }
 return ans%mod;
}

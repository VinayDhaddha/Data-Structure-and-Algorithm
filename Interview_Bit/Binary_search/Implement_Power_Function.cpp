// time complexity=O(logN)
// space complexity=O(logN) -->because of reccursion & it can be improved upto O(1) when we use loop instead of reccursion
int Solution::pow(int x, int n, int d) {
    long long int sum=0,flag=0;
    if(n==0)                        // x^n =0 always
        return 1%d;
    if(x==0)                        // x^n =1 always
        return 0;
    if(n==1){                       // with n==1 
        sum=x;                              
        if(sum<0){                  // ***important line*** if sum<0 then keep in mind while taking mod b/w any two number the result should always be +ve
            sum=sum%d;
            sum=d+sum;
        }
        return sum%d;               // return 
    }
    if(n%2!=0){                     // if n is odd then can divide n only when by decreasing value of n by 1 
        flag=1;
        n=n-1;
        sum=pow(x,n/2,d);           // reccursive call for half
        sum=sum%d;
        sum=(sum*sum)%d;            // multiplying both half
        sum=(sum*x)%d;                  // now multiplying the value at this point earlier as power was odd 
        sum=sum%d;
        if(sum<0){
            //sum=sum%d;
            sum=d+sum;
        }
        return sum%d;
    }
    else{                       // if n is even then we can easily divide and apply for reccursive call
        sum=pow(x,n/2,d);
        sum=sum%d;
        if(sum<0){
            sum=sum%d;
            sum=d+sum;
        }
        return (sum*sum)%d;
    }


}


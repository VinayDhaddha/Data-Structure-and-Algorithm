int Solution::isPalindrome(int A) {
        int num=A,temp=0;
        if(A<0){
            return 0;
        }
        while(num!=0){
            temp=temp*10+num%10;
            num=num/10;
        }
        // cout<<temp<<endl;
        if(temp==A){
            return 1;
        }

        else{
            return 0;
        }
}


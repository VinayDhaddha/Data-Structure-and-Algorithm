time complexity=O(N)

int Solution::power(string A) {
    int N = A.length();
    int num = A[0]-'0';
    for(int i = 1; i<N; i++) num = (num*10)+(A[i]-'0');
    if(num == 1) return 0;
    //Method 1
        // int power = log(num)/log(2);
        // if(pow(2,power) == num) return 1;
        // else return 0;
    
    // method 2
        // multipe 2 with num=2 until we get num==A
    
    //Method 3
    //for eg: 8 - 1000 and 7 - 0111. So 1000&0111 = 0. 
    if((num & (num-1)) == 0) return 1;
    return 0;
    
}

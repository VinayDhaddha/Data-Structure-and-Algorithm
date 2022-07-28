// time complexity=O(N^3/2)
// space complexity=O(1)
int check(int a){
    for(int i=2;i<=sqrt(a);i++){
        if((a%i)==0){
            return 0;
        }
    }
    return 1;
}
vector<int> Solution::primesum(int A) {
    vector<int> v;
    int j;
    for(int i=2;i<=A/2;i++){
        j=A-i;
        int a=check(i);
        int b=check(j);
        if(a&&b){
            v.push_back(i);
            v.push_back(j);
            break;
        }
        j--;
    }
    return v;
}


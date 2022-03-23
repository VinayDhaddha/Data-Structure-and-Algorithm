// time complexity=O(logN)
// space complexity=O(logN)
int Solution::solve(vector<int> &A, int B) {
    int i=upper_bound(A.begin(),A.end(),B)-A.begin();       // upper_bound fxn gives address of first element in array thaats 
                //value is grater then value B or gives last adress if value not present in array
 
    return i;
}


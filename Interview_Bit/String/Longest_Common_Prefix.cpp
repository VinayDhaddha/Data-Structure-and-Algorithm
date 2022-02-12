//TIME Complexity=O(length of 1st string)*(sum of lenght of remaining string in vector)
// space complexity=O(length of 1st string)
// given in question prefix lonfest string
string Solution::longestCommonPrefix(vector<string> &A)
{
    sort(A.begin(),A.end());
    string b;
    for(int i=0;i<A[0].length();i++){
        bool flag=true;
        for(int j=1;j<A.size();j++){
            if(A[j][i]!=A[0][i]){
                flag=false;
                return b;
            }
        }
        b.push_back(A[0][i]);        
    }
    return b;
}

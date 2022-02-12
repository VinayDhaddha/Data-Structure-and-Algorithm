// time complexity=O(N)
// SPACE complexity=O(1)
int Solution::solve(string A) {
    int count=0,i=0,sum=0;
    while(A[i]!='\0'){
        if((A[i]=='a')||(A[i]=='e')||(A[i]=='e')||(A[i]=='i')||(A[i]=='o')||(A[i]=='u')){   // counting vowels
            count++;
        }
        i++;
    }
    sum=A.size()-count;             // rest are consonents
    sum=sum*count;                  // product gives reqired ans (beacause number of substrings in A which starts with vowel and end with consonants or vice-versa.)
    
// return ans%1000000007;
    return sum%1000000007;
}


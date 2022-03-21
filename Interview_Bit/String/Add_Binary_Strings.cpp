// time cmplexity O(N)
// space complexity O(N)

string Solution::addBinary(string A, string B) {
    int carry=0,sum;
    string s; // storing sum from end to 0 
    int i=A.size()-1,j=B.size()-1;
    while((i>=0)||(j>=0)||carry){ // loop for finding sum till smallest strings end
        sum=carry;              // sum= carry+A[i]+A[j]
        if(i>=0){           // adding A[i] char to sum
            sum+=(A[i]-'0');
        }
        if(j>=0){           // adding B[j] char to sum
            sum+=(B[j]-'0');
        }
        s.push_back((char)('0'+sum%2));// finding resultant of (A[i]+B[j]+carry) in binary so mod2
        carry=sum/2;// carry
        i--;
        j--;
    }
    i=s.size()-1;// to reverse use  reverse(s.begin(),s.end());
    A.clear();
    while(i>=0){
        A.push_back(s[i]);
        i--;
    }
    return A;
}


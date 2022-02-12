// time complexity-O(N^2)
// SPACE COMPLEXITY-O(N)
string Solution::countAndSay(int A) {
    string s,s1;
    int size,i=0,cnt=0,prev=0;
    if(A==0)
        return s;// returning NULL string
    s.push_back('1');// intialised the string with characters
    size=1;// current value of string
    while(size<A){// while  to reached the size<A
        i=0,cnt=0,prev=0;
        while(s[i]!='\0'){// iteration along the string
            if(s[i]==s[prev]){// while A[prev]==A[i] count increases
                cnt++;
            }
            else{// else first push count and then push no. which was counted
                s1.push_back((char)(cnt+'0'));//*******(imp)storing count to s1 string as char (char)(cnt+ascii of '0')
                s1.push_back(s[prev]);
                prev=i;
                cnt=1;
            }
            i++;// increment in iterator
        }
        if(prev!=i){// if loop complets to traverse along string completes but prev and i points to different index
            s1.push_back((char)(cnt+'0'));
            s1.push_back(s[prev]);
        }
        i=0;
        s.clear();// important  to clear to perform fxn in less memory space
        while(s1[i]!='\0'){// storing s1 content in s string
            s.push_back(s1[i]);
            i++;
        }
        s1.clear();
        size++;
        // s=count_say(size,s,A);
    }
    return s;
}


// time complexity=O(N)
// space complexity=O(1)

// Approach
// 1.Remove wide space from start(i) ,end(j)
// 2.check i<=j if yes continue,else return 0
// 3 check +,- at i index,& traverse along string one '.' and one 'e' posibble in numeric no.
// 4 if 'e' or '\0' come just  after '.' not a numeric string
// 5. if '.' or '\0'  come just  after 'e' not a numeric string. '+' or '-' once allowed just after 'e' && (e1.0 is inalid).................
int Solution::isNumber(const string A) {
    int i=0,j=A.size()-1,flag_e=0,flag_dot=0;
    if(A.size()==0)  // returning 0 for NULL string
        return 0;
    while((A[i]==' ')&&(i<A.size())){// removing widespaces from start
        i++;
    }
    while((A[j]==' ')&&(j>=0)){//removing widespaces from end
        j--;
    }   
    if(j<i){   // checking for i and j
        return 0;
    }
    if((A[i]=='-')||(A[i]=='+')){ // allowing once + or - sign in string of numeric
        i++;
        if((A[i]=='\0')||(i>j)){// but not only sign it also have a number followed by sign otherwise return 0
            return 0;
        }
    }
    while(i<=j){
        if(((A[i]>='0')&&(A[i]<='9'))||((A[i]=='e')&&(flag_e==0))||((A[i]=='.')&&(flag_dot==0))){// checking for number,decimal no. and for 'e'    . .  ..  . . 
            if(A[i]=='e'){// 5th point of approach
                flag_e=1;
                flag_dot=1;
                if(A[i+1]=='\0')
                    return 0;
                if((A[i+1]=='+')||(A[i+1]=='-')||((A[i+1]>='0')&&(A[i+1]<='9'))){
                    i++;
                }
                else{
                    return 0;
                }
            }
            else if(A[i]=='.'){// 4th point of approach
                flag_dot=1;
                if((A[i+1]=='\0')||(A[i+1]=='e')){
                    return 0;
                }
            }
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}



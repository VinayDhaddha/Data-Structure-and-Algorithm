// TIME COMplexity=O(N)
// space complexity=O(1)

// note when try to  form  string contain whitespace characters before the number in constum input that whitespace automaticcally removes
int Solution::atoi(const string A) {
    string max="2147483647";
    string min="-2147483648";
    if(A.size()==0)         
        return 0;
    int i=0,sign=1,l=0,flag=0;
    long long int num=0,result;
    // ----------------------SECTION checking either interger overflow or not
    if(A[0]=='-'){                  // checking if negaive sign present then our numeric value will be -ve
        // printf("yes\n");
        for(i=1;(i<min.size())&&(i<A.size());i++){              // loop iterate while i<min.size()  && i<A.size() 
            if((A[i]<'0')||(A[i]>'9')||(A[i]==' '))             // when we get garbage value or ' '  then break
                break;
            else if(A[i]>min[i]){               // comparing  helps to check for boundary i.e it crosses INT_MIN  val incase if i>min.size() 
                // l++;
                flag=1;
            }
            // l++;
        }
        // printf("l=%d  min_size=%d\n",l,min.size());
        if(((i==min.size())&&(flag==1))||((i<A.size())&&(A[i]>='0')&&(A[i]<='9')))  // if condition are met then string numeric value definatly overflows
            return -2147483648;
        
        
        // for(i=1;(i<min.size())&&(i<A.size());i++){
        //     if((A[i]<'0')||(A[i]>'9')||(A[i]==' '))
        //         break;
        //     else if(A[i]>min[i])
        //         return -2147483648;
        // }
        // if((i<A.size())&&(A[i]>='0')&&(A[i]<='9'))
        //     return -2147483648;
    }
    else if((A[0]=='+')||(A[i]>='0')&&(A[i]<='9')){// checking if positive sign present then our numeric value will be +ve
        if(A[0]=='+')
            i=1;
        for(i=i;(i<max.size())&&(i<A.size());i++){      // loop iterate while i<min.size()  && i<A.size() 
            if((A[i]<'0')||(A[i]>'9')||(A[i]==' '))     // when we get garbage value or ' '  then break
                break;
            else if(A[i]>max[i]){           // comparing  helps to check for boundary i.e it crosses INT_MAX  val incase if i>max.size() 
                // l++;
                flag=1;
            }
            // l++;
        }
        if(((i==max.size())&&(flag==1))||((i<A.size())&&(A[i]>='0')&&(A[i]<='9')))      // if condition are met then string numeric value definatly overflows
            return 2147483647;
    }
    //---------------------------------Now we are sure that numeric value doesnot overflow----------------------------------------------------------------
    i=0;
    // cout<<A<<endl;
    while(i<A.size()){          // loop helps to find numeric value along with the sign
        // printf("yes2\n");
        if(i==0){
            if(A[i]=='-'){
                sign=-1;
                i++;
            }
            else if(A[i]=='+'){
                sign=1;
                i++;
            }
        }
        if((A[i]>='0')&&(A[i]<='9')){
            num+=(A[i]-'0');
            num=num*10;
        }
        else{
            // printf("yes1\n");
            // printf("break num=%lld\n",num);
            break;
        }
        i++;
    }
    num=num/10;
    num=num*sign;
    return num;
}


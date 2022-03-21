// Time complexity: O(N)
// SPACE complexity: o(1)

// IMP LINE: insertion from the end

int Solution::solve(string A) {
    int start=0,end=A.size()-1,count=0,flag=0;//count=points to inddex from which we gets palindrome 
    while(start<end){   // loop while (start<end)                    
        if(A[start]!=A[end]){// when we get A[start]!=A[end]
            if(flag==1){        // flag==1 when we previously get two character same from start ,end equal we assume it may be starting of palindrome
                flag=0;             // flag=0 i.e  count storing index is not starting of paindrome (i.e our assumsion of palindrome is wrong)
                end=A.size()-1;     // insertion at end so restart to compare from end from present index of start
            }
            else
                start++;// increment in iterator start to check palindrome from next char with end character 
        }
        else{// when we get A[start]==A[end]
            if(flag==0){// start index may be the starting of palindrome
                count=start; // if start index is starting of palindrome in string then count stores length of char to insert in A string to make it a A palindrome
                flag=1;    // indicates we already assumed one points as a starting of palindrome
            }
            end--;
            start++;
        }
    }
    if(flag==0){// flag==0 indicates no assumption of starting of palindrome 
        count=start;// start containing the min length to insert to make string A a palindrome 
    }
    // if flag==1 we already assumed a starting point of palindrome that was correct so count alreay containing thr min length to insert to make string A a palindrome
    return count;
}


// Time complexity=O(N)
// Space Complexity=O(1)
bool alphaNumeric(char ch)// fxn to skit non alphanumeric numbers
{
    if( (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int flag=1;//  removing exactly one character so flag=1
int check(string A,int s,int e){ //sub fxn to check wheather string from index s to e is palindrome or not
    bool palin = true;
    int start = s;
    int end = e;
    while(start < end)
    {
        while( start < end && !alphaNumeric(A[start]))
        {
            start++;
        }
        
        while( start < end && !alphaNumeric(A[end]))
        {
            end--;
        }
        
        if(start < end)
        {
            char ch1 = A[start];
            char ch2 = A[end];
            
            if(ch1 >= 'A' && ch1 <= 'Z')
            {
                ch1 = ch1 + ('a' - 'A');
            }

            if(ch2 >= 'A' && ch2 <= 'Z')
            {
                ch2 = ch2 + ('a' - 'A');
            }
            
            if(ch1 != ch2)
            {
                palin = false;
                break;
            }
            start++;
            end--;

        }
    }

    return palin;
}
int Solution::solve(string A) 
{
    bool palin = true;
    int start = 0;
    int end = A.size(),check1,check2;
    flag=1;             // here we can n digit to check string is palindrome or not removing after removing n characters
    while(start < end)
    {
        while( start < end && !alphaNumeric(A[start]))// removes non alphabumeric from start
        {
            start++;
        }
        
        while( start < end && !alphaNumeric(A[end]))// removes non alphabumeric from end
        {
            end--;
        }
        
        if(start < end)// loop to check palindrome or not
        {
            char ch1 = A[start];//storing character at index =start
            char ch2 = A[end];//storing character at index =end
            
            if(ch1 >= 'A' && ch1 <= 'Z')// changing upper character to upper case 
            {
                ch1 = ch1 + ('a' - 'A');
            }

            if(ch2 >= 'A' && ch2 <= 'Z')// changing upper character to upper case
            {
                ch2 = ch2 + ('a' - 'A');
            }
            
            if(ch1 != ch2)// if ch1 !=ch2
            {
                if(flag==1){// counting how much character we can eliminate// adding this 'if' in check fxn then  we can check string is palindrome or not removing after removing n characters
                    flag--;
                    // printf("%d   %d \n",start,end);
                    check1=check(A,start,end-1);// decreasing end index
                    check2=check(A,start+1,end);// increasing starting index
                    
                    if(check1||check2){// if either or check, check2 == 1 then we got a palindrome 
                        break;                    
                    }
                    else{ // if either or check, check2 == 0 then no palindrome found
                        palin = false;
                        break;                           
                    }
                }
                else{// if flag==0
                    palin = false;
                    break;
                }
            }
            start++;
            end--;

        }
    }

    return palin;
}

// TIME complexity=O(N)
//  Space complexity=O(1)

//IMMMM=3999
int find_val(char s){  // Returning the ROMAN character value
    switch(s){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}
int Solution::romanToInt(string A) {
    int i=0,j=0,ptr1,value=0;
    if(A.size()==0)//if NO input 0 is o/p
        return 0;
    else{
        while(A[i+1]!='\0'){ // traversing the string
            if(find_val(A[i])>=find_val(A[i+1])){//if A[i]>=A[i+1]  eg VI(interger value of V>I ie(5>1)) or VV (similarly 5==5) 
                value+=find_val(A[i]);// Adding greatest char value   // at ith index we get greater value character of string (j to i+1)
                ptr1=i;
                ptr1--;
                while(ptr1>=j){ // substracting character value from index j to i-1 to find value of roman no.
                    value-=find_val(A[ptr1]);
                    ptr1--;
                }
                j=i+1; // iterator points to i+1 index
            }
            i++; // incrementing i because we have to substract this index character  value from next greatest character value  
        }
    }
    if(j<=i){// strings end so 
        ptr1=i;
        value+=find_val(A[ptr1]);// Adding greatest char value by default greatest character is last character of string as string ends
        ptr1--;
        while(ptr1>=j){ // substracting character value from index j to i-1 to find value of roman no.
            value-=find_val(A[ptr1]);
            ptr1--;
        }
    }
    return value; // return integer value of roman character
}


// time complexity=O(max(min(N,M),(max(N,M)-min(N,M)))
// space complexity=O(1)

int Solution::compareVersion(string A, string B) {
    long long unsigned i=0,j=0,count1=0,count2=0;// important step using long long unsigned
    while((A[i]!='\0')&&(B[j]!='\0')){// traversing both string 
    
        while((A[i]!='\0')&&(A[i]!='.')){// traversing string A while '.' or '\0' comes
            count1=count1*10+(A[i]-'0'); // finding the string value 
            i++;
        }
        while((B[j]!='\0')&&(B[j]!='.')){// traversing string B while '.' or '\0' comes
            count2=count2*10+(B[j]-'0');// finding the string value 
            j++;
        }
        // comparing both values
        if(count1>count2){
            return 1;  // version 1 greater
        }
        else if(count1<count2){
            return -1;// version 2 greater
        }
        // else it means both count are same as (1.01==1.1)
        count1=0;// reinitializing
        count2=0;//reinitializing
        i++;
        j++;
    }
    if((A[i]=='\0')&&(B[j]=='\0'))// if both i,j pointing to '\0' it means both version are same 
        return 0;
    else if(A[i]=='\0'){// it means 'j' does not reach to '\0' of B yet
        while((B[j]!='\0')&&(B[j]!='.')){
            count2=count2*10+(B[j]-'0');// finding the string value 
            j++;
        }
        if(count2==0)// if count2==0 it means only '0' is present in B
            return 0;// so both version are same
        else
            return -1;// version 2 greater
    }
    else{
        while((A[i]!='\0')&&(A[i]!='.')){// it means 'i' does not reach to '\0' of A yet
            count1=count1*10+(A[i]-'0');// finding the string value
            i++;
        }
        if(count1==0)// if count1==0 it means only '0' is present in A
            return 0;// so both version are same
        else
            return 1;// version 1 greater
    }
}


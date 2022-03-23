// time complexity=O(NlogN)
// space complexity=O(N)
int Solution::solve(vector<int> &A, int B) {
    vector<int> arr;                // arr used to store the sorted array as we are going to do chaanges in A
    int i=0,prev=0,h=0,sum=0;
   sort(A.begin(),A.end());             // sorting
    for(i=0;i<A.size();i++){        // assigning values to arr from A
        // printf("---->%d\n",A[i]);
        arr.push_back(A[i]);
    }
    for(i=0;i<A.size();i++){        //total meters of wood we get after cutting tree of height arr[i] stored to A[i]
        h=A[i];
        A[i]=(A[i]-prev)*(A.size()-i);
        // printf("---->%d\n",A[i]);
        prev=h;
    }

    i=A.size()-1;
    while((i>=0)&&(sum<B)){             // iterating from end to start
        // printf("$$$$%d----->%d  \n",i,A[i]);
        sum=sum+A[i];               //adding sum of meter of tree we get when we set machine to cut tree at height arr[i]
        i--;
    }
    // printf("sum=%d     i=%d \n",sum,i);
    if(sum==B){                     // if sum==B 
        if(i<0)                 // i<0 means no tree left so (height set =0)
            return 0;
        else{                   // else return arr[i] value
            return arr[i];
        }
    }
    else if(sum>B){             //if sum>B (means we hace to take height b/w arr[i] to arr[i+1])

        if(i<0){                    // if i<0
            i++;                    
            sum=sum-B;
            
            return  0 +floor(sum/(A.size()-i));   // IMP line helps to find height to be set in machine
        }
        else{
            i++;
            sum=sum-B;
           return (arr[i-1]+floor(sum/(A.size()-i)));   // ar[i]+ (how much above arr[i] to get req ans)
            
        }
    }
    else{
        h= 0;       // else h=0
    }
    return h;
}


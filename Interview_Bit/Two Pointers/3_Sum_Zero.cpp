// O(n^2)
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int i=0,start=i+1,end=A.size()-1,find,prev=-1;
    vector<vector<int>> arr;
    if(A.size()<3)   // checking whether size < 3 if yes elimiate it and return empty vector 
        return arr;
    sort(A.begin(),A.end());  // sorting vector A
    for(i=0;(i<(A.size()-2));i++){  // iterator 'i ' from 0 to A.size()-2 becoz at A.size()-1 end is already pointing 
        // start=i+1;
        if(i>=1){    // only for i=0
            if(A[i]==A[i-1])    // to eleminate repetation of same no. once processed from index i
                continue;
        }
        start=i+1;    // initializing ptr1
        end=A.size()-1;    // initializing ptr2
        while(end>start){ // A[i] other two no. who's sum ==0 only found from index start to end 
            long long int sum=(long long int)A[i]+(long long int)A[start]+(long long int)A[end]; 
            if(sum==0){   // we got a triplet 
                vector<int> triple={A[i],A[start],A[end]};
                
                arr.push_back(triple);
                end--;          // chances to get more triplets 
                while((A[end+1]==A[end])&&(end>start))  // to eleminate repetation of same no. once processed from end 
                     end--;   // we got a triplet chances to get more triplets 
        //------------------or------------------ we can replace above 3 line with
            //     start++;
            //     while((A[start-1]==A[start])&&(end>start))  
            //          start++;   
            // }
            }
            else if(sum<0){   // increment at index start to increase sum value near to zero
                start++;
            }
            else{
                end--;    // decrement  at index end to increase sum value near to zero
            }
        }
    
    }
    return arr;  // return 2d vector containing triplets
}






    //important question
    int Solution::solve(vector<int> &A, int B) {
        int i=0,j=0,sum=0,count=0;
        while(j<A.size()){
            sum+=A[j];
            if(sum<B){
                count=count+j-i+1;
                // printf("count1=%d\n",count);
            }
            else{
                while((sum>=B)&&(i<A.size())){
                    if(i==j){
                        i=j+1;
                        sum=0;
                        // printf("break sum=%d\n",sum);
                        // break;
                    }
                    else{
                        sum=sum-A[i++];
                    }
                }
                if(i<=j){
                    // printf("count2=%d\n",count);            
                    count=count+j-i+1;
                }
            }
            j++;
        }
        // while(i<A.size()){
        //     count=count+j-i+1;
        //     i++;
        // }
        return count;
    }



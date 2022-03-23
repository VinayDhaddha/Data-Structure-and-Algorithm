// time complexity=O(logN)
// space complexity=O(logN)
int binary_search(vector<vector<int> > &A,int flag,int rw,int c,int l,int r,int B){     // customized binary search
    if(l<r){
        int mid=l+floor((r-l)/2);
        if(flag==1)                     // if flag==1 then r=then binary applied to search for row
            rw=mid;
        else                            // if flag==0 then r=then binary applied to search for column
            c=mid;
        if(A[rw][c]==B)                     // if we get value then return mid value
            return mid;
        else if(A[rw][c]>B){                    // half left search
            return binary_search(A,flag,rw,c,l,mid-1,B);
        }
        else{
            return binary_search(A,flag,rw,c,mid+1,r,B);        // half right search
        }
    }
    else 
        return l;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // printf("%d\n",A[0].size());
    int row,column;
    row=A.size();
    row=binary_search(A,1,0,0,0,row-1,B); // binary search to select row
    if(A[row][0]==B)
        return 1;
    else if(A[row][0]>B){
        row=row-1;
        if(row<0)
            return 0;
    }
   // printf("------%d-----\n",row);
    column=A[0].size();
    column=binary_search(A,0,row,0,0,column-1,B);           // binary search to select column
    //printf("------%d-----%d\n",row,column);
    if(A[row][column]==B)
        return 1;
    else 
        return 0;
}


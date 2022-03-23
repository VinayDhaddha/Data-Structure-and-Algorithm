
// space and time complexity=O(logn)
int binary_a(const vector<int> &A,int l,int r,int B,int flag){ // searching recurrsively
    if(l<=r){  // include last condition when l==r
        int mid=l+floor((r-l)/2);       // correct way of finding mid
        if(A[mid]==B){                  // when got the element
            if(((mid-1)>=0)&&(A[mid-1]==B)&&(flag==0)){         // if its prev elment is same then adain recc call for checking left most element
                return binary_a(A,l,mid-1,B,flag);
            }
            else if(((mid+1)<A.size())&&(A[mid+1]==B)&&(flag==1))   //if element next to mid is same then recc call to check right most element
                return binary_a(A,mid+1,r,B,flag);
            else 
                return mid;             // else return mid
        }
        else if(A[mid]>B)               // condn of binary search  for left search
            return binary_a(A,l,mid-1,B,flag);
        else                            // condn of binary searching for right search
            return binary_a(A,mid+1,r,B,flag);
    }
    else            // nothing get  so return 0
        return -1;            
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> ans(2,-1);
    int l=0,r=A.size()-1;
    l=binary_a(A,l,r,B,0);  // checks left most occurence  & 0 used to indicate left most search
    r=binary_a(A,l,r,B,1);   // checks right most occurence  & 1 used to indicate left most search
    // cout<<"l="<<l<<"   r="<<r<<endl;
    if((l==-1)||(r==-1))        // any of l & r ==-1 return 0
        return ans;
    ans[0]=l;
    ans[1]=r;
    return ans;       //return req ans 
}


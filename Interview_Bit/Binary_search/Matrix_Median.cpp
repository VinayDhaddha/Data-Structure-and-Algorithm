// IMPORTANT QUESTION
// time complexity=O(NlogM)
// space complexity=O(1)
int Solution::findMedian(vector<vector<int> > &A) {
    // printf("$$$%d\n",*(A[0].begin()));
    int m = A.size();
    int n = A[0].size();
    
    int max = A[0][0], min = A[0][0];
    
    
    for(int i = 0; i < m; i ++) {   // finding min and max elements
        if(A[i][0] < min) min = A[i][0];
        if(A[i][n-1] > max) max = A[i][n-1];
    }
    
    int required = (m * n + 1) / 2;
    
    while(min < max) {              // binary search concept
        int sum = 0;
        int mid = (min + max) / 2;
        for(int i = 0; i < m; i ++) {                       // finding upper bound for each row
            // Count the number of elements lower than or equal to mid
            // i.e How many numbers is mid greater than or equal to
            // in each row using upper_bound function in STL
            //printf("$$$$$%d\n", upper_bound(A[i].begin(), A[i].end(), mid)- A[i].begin());
            sum += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
    
        if(sum >= required) {               // if upper bound value > req then max=mid
            max = mid;
        }
    
        else min = mid + 1;             // else min=mid+1
        //else max = mid;
    }
    
    return max;
// return 0;
}

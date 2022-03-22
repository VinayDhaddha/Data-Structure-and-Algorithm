int Solution::maxArea(vector<int> &A) {
    int i=0,j=A.size()-1,area=0,max=-1;
    while(i<j){
        area=(j-i)*min(A[i],A[j]);
        if(area>max)
            max=area;
        if(A[i]<=A[j])
            i++;
        else
            j--;
    }
    return max;
}


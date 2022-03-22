void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int c0=0,c1=0,c2=0;
    for(int j = 0; j < n; j++){
    if(A[j] == 0){
    c0++;
    }
    else if(A[j] == 1){
    c1++;
    }
    else{
    c2++;
    }
    
    }
    int l =0;
    for(int k = 0; k < c0; k++){
    	A[l++] = 0; 
    }
    for(int k = 0; k < c1; k++){
    	A[l++] = 1; 
    }
    for(int k = 0; k < c2; k++){
    	A[l++] = 2; 
    }
}


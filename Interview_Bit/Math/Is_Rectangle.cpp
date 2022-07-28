// time complexity=O(1)
// SPACE complexity=O(1)
int Solution::solve(int A, int B, int C, int D) {
    if(A==B){
        if(C==D){
            return 1;
        }
        else
            return 0;
    }
    if(A==C){
        if(B==D){
            return 1;
        }
        else
            return 0;
    }    
    if(A==D){
        if(C==B){
            return 1;
        }
        else
            return 0;
    }
    return 0;
}


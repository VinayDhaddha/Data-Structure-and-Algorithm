// time complexity- O(N)
// Space complexity O(N)

string Solution::solve(string A) {
    int ptr,j=A.size()-1,l=0,flag=1;
    string B;// where we store o/p and return 
    while(j>=0){
        while((j>=0)&&(A[j]!=' ')){// calcutes length of words and starting index of word
            j--;
            l++;
        }
        if(l==0){// case1 widespace at (head,mid,tail)
            if((j!=(A.size()-1))){// implies no widespaces at tail
                while(A[j]==' '){
                    j--;
                }
                if(j<0)// helps to remove widespaces from head side
                    break;
                else
                    B.push_back(' ');// decrease mid widspace to single widespaces
            }
            else{
                while(A[j]==' ')// neglects widespaces at the tail
                    j--;
            }
        }
        ptr=j+1;//ptr points to word startig index as j points to A[j]==' '
        while(l>0){// pushing word into B string
            B.push_back(A[ptr]);
            ptr++;
            l--;
        }
    }
    ptr=j+1;// loop breaks when j<0 so if l==0 directly return B string
    while(l>0){
        B.push_back(A[ptr]);
        ptr++;
        l--;
    }
    return B;
}



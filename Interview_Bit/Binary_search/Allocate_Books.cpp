// important question
// time complexity=O(NlogN)
// space complexity=O(1)
int count_student(vector<int> &A, int p){ // counting that max of p number of pages covering all the students 
    int i=0,sum=0,s=0;
    while(i<A.size()){
        if((sum+A[i])<=p){

            sum+=A[i];
            i++;
        }
        else{
            sum=0;
            s++;
        }
    }
    if(sum>0)
        s++;
    return s;
}
int Solution::books(vector<int> &A, int B){
    if(A.size()<B)      // if number of books < number of students then return -1
        return -1;
    int max=INT_MIN,i,sum=0,l,r,min_pages,s;        
    for(i=0;i<A.size();i++){        // finding max number of pages in a  book (act as lower bound )& finding sum of total pages
        if(A[i]>max)
            max=A[i];
        sum+=A[i];
    }
    l=max;              // max no. of pages act as left pointer
    r=sum;              // sum of all no. of pages act as right pointer for binary tree
    min_pages=max;      // min pages ==max no. of pages present in a particular among rest of the book (act as lower bound as Each student has to be allocated at least one book )
    while(l<=r){            // binary search on max number of pages covering all the students  
        int mid=l+floor((r-l)/2);
        s=count_student(A,mid);
        if(s<B){       // s<B means all students not get even a single book  decreasing right pointer helps to derease mid value
            r=mid-1;
        }
        else if(s>B){       // s>B means more than B students get  book(which is not possible)  so increasing left  pointer helps to increase mid value
            l=mid+1;
        }
        else{           // else it may also possible to have more minimum no of pages so decresing r value
            min_pages=mid;
            r=mid-1;
        }
    }
    return min_pages;
    
}

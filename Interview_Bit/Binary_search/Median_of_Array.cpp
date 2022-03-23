double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m=A.size();
    int n=B.size();
    int min,max,count=0,i=0,num=0,mid=0,sum=0,m1,m2;
    double total=0;
    if(m==0){
        min=B[0];
        max=B[B.size()-1];
        if(n%2!=0){
            mid=floor(n/2);
            total=B[mid];
            return total;
        }
        else{
            mid=floor(n/2);
            total=(B[mid]+B[mid-1])/(2.0);
            return total;            
        }
    }
    else if(n==0){
        min=A[0];
        max=A[A.size()-1];
        if(m%2!=0){
            mid=floor(m/2);
            total=A[mid];
            return total;
        }
        else{
            mid=floor(m/2);
            // printf("mid=%d\n",mid);
            total=(A[mid]+A[mid-1])/(2.0);
            return total;            
        }
    }   
    else{
        min=A[0]<B[0]?A[0]:B[0];
        max=A[A.size()-1]>B[B.size()-1]?A[A.size()-1]:B[B.size()-1];
        if(((m+n)%2)!=0){
            count=1;
            num=(m+n+1)/2;
        }
        else{
            count=2;
            num=(m+n)/2;
        }
        m1=min;
        m2=max;
        while(i<count){
            sum=0; 
            min=m1;
            max=m2;
            while(min<max){
                // printf("&&&&&&&&&i=%d&\n",i);
                sum=0;
                mid=min+floor((max-min)/2);
                sum=upper_bound(A.begin(),A.end(),mid)-A.begin()+upper_bound(B.begin(),B.end(),mid)-B.begin();
                if(sum>=num)
                    max=mid;
                else
                    min=mid+1;
            }
            i++;
            num++;
            // printf("$$$total=%f$$max=%d\n",total,max);
            total+=max;
            // printf("$$$$$$$$@@@@@@@@@total=%f",total);
        }
        if(count==1){
            // printf("yes11111111111111111\n");
            return total;
        }
        else{
            // printf("yes2222222222222\n");
            return total/2;
        }
    }
}


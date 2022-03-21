//Time complexity=O(N)
// Space complexity=O(N)
string Solution::convert(string A, int B) {
    if (B==1)               //B represent no. of rows if B==1 teh return A string as it is already single row 
        return A;
    int dif=(B-1)*2,d2,prev;       // dif==(3-1)*2  maximum difference b/w index of 2 char
                            //P.......A........H.......N
    int i;                   // ..A..P....L....S....I...I....G
    int count=0;              //....Y.........I........R
    d2=dif;// indicates which diffence we have to add current index helps to move to next comming char as per row zig-zag movement 
    string s;
    while(count<B){//loop while count<row no. because we start from index=0 n count
        prev=d2;// gives previous value of d2
        for(i=count;i<A.size();){// loop to iterate in the string
            s.push_back(A[i]);// pushing value
            i+=d2;// i index increment by d2 value
            if((d2!=dif)&&(d2!=0)){// if d2!=dif
                d2=abs(dif-d2);// example:  A 1 P 1 L  ((gap b/w A&P) +(gap b/w P&L))=dif
            }
        }
        
        d2=prev-2;// exmaple gap b/w P&A(row 1) =4, gap b/w A&P(row 2) =2, 
        if(d2==0)// at gap b/w Y&I  d2=0 as per prev line of code 
            d2=dif; // d2=dif otherwise loop will never terminate
        count++;// increasing count indicates stating sindex of each row
    }
    return s;// return string s;
}


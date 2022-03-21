// time complexity= O(N)
// space complexity=O(N)
// important lines :
// Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
// Extra spaces between words should be distributed as evenly as possible.
// If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text, it should be left justified and no extra space is inserted between words
vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> v;
    if(A.size()==0)// if i/p string is empty return empty vector<string>
        return v;
    int word=0,i,size=0,prev=0,space=0,k,temp;//word=count words in selected string  , size=size of selectrd string ,prev=index of fisrt word of string in vector A,space= count normal spaces b/w each word  , temp = extra spaces other then normal spacings
    string sp1="",sp2="";// sp1 = normal spaces b/w each word   ,  sp2=extra spaces other than normal spacings  
    string s="";// string wepush into our o/p vector<string>
    for(i=0;i<A.size();i++){
        if(size<=(B-word+1)){//size(contain length of string of CHARACTER APLHA  )<=B-(word-1)  (normally b/w 2 words one spacing is required   then b/w 'N' words N-1 spaces must required  NOT INCLUDING THESE SPACES IN SIZE becoz size valrialbe required for further use)
            size+=A[i].size();// recalculating the size of strings we can store
            word++;// calculating WORDS we already stored 
            
        }
        if(size>(B-word+1)){//limit of each line limit exceeds
            size=size-A[i].size();// deleting last string traversed length
            i--;//decrementing i
            word--;//so WORD count also decreases
            if(word==1){//if only word word we have in a line the FIRST insertthat word and rest of the spaces for " "
                space=B-size;// count of spaces to be filleds after strings
                temp=0;// no extra spaces
            }
            else{
                space=floor((B-size)/(word-1));// general spacing b/w each word
                temp=(B-size)%(word-1);// extra spacing count filled from left to right
            }
            for(k=0;k<space;k++){
                sp1+=" ";// string of general spacing
            }
            sp2+=" ";// extra spaces string came in use until temp!=0
            s="";// Null initializing string
            for(k=prev;k<i;k++){// inserting strings with spacing in s
                s+=A[k];        // strings from vector<string> A
                if(temp!=0){    // extra spacing becoz left have more spacing then right 
                    s+=sp1+sp2;     // general spacing + extra spacing
                    temp--;         // decrement in extra spacing
                }
                else
                    s+=sp1;     // when no extra spacing left use only genralized spacing
            }
            if(k==prev){// if only one word in line
                s=A[k];  // inserting the word first
                s+=sp1; // then general spacing 
                while(temp!=0){  // remaining with extra spaing
                    s+=sp2;
                    temp--;
                }
            }
            else
                s+=A[k]; // insrting last word of string
            v.push_back(s);// inserting a LINE in vector 
            size=0;
            word=0;
            prev=i+1;// changing PTR indicated from which index we have to take strings for next line
            sp1="";
            sp2="";
            s="";
        }
    }
    // loop terminated 
    // case1: size< B-(word-1)
    // solving case1
    s=A[prev];
    for(i=prev+1;i<A.size();i++){
        s+=" ";// only single space required b/w each word in last line
        s+=A[i];
    }
    size=s.size();
    while(size<B){// filling rest of spaces with " "
        s+=" ";
        size=s.size();
    }
    if(prev<A.size())
        v.push_back(s);
    return v;
}


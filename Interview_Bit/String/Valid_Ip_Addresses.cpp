int sval_in_int(string s){
    int i=0,count=0;
    while(s[i]!='\0'){
        count=count*10+(s[i]-'0');
        i++;
    }
    return count;
}
// time complexity=O(1)
// space complexity=O(n)
vector<string> Solution::restoreIpAddresses(string A) {
    int i=0,j=0,k=0,l=0;
    vector<string> v;
    if((A.size()<4)||(A.size()>12))
        return v;
    for(i=1;i<=3;i++){ // i=1 must otherwisse thosecases includes in which first bloock of ip address is empty  ex .252.246.255
        for(j=1;j<=3;j++){
            for(k=1;k<=3;k++){
                for(l=1;l<=3;l++){
                    if(((i+j+k+l)>A.size())||((i+j+k+l)<A.size()))  // to check the length of all blocks == A.size(), if not then continue
                        continue;
                    string a=A.substr(0,i);     // getting substring 1st
                    string b=A.substr(i,j);         // getting substring 2nd
                    string c=A.substr(i+j,k);       // getting substring 3rd
                    string d=A.substr(i+j+k,l);     // getting substring 4th
                    if(((sval_in_int(a)>255)||(sval_in_int(b)>255)||(sval_in_int(c)>255)||(sval_in_int(d)>255)))// if int values of a,b,c,d>255 continue
                        continue;
                    if(((a[0]=='0')&&(a.size()>1))||((b[0]=='0')&&(b.size()>1))||((c[0]=='0')&&(c.size()>1))||((d[0]=='0')&&(d.size()>1))) /// as we know The numbers cannot be 0 prefixed unless they are 0 if it occure then continue the process
                        continue;
                    v.push_back(a+"."+b+"."+c+"."+d);       // pushing strings into the required ans 
                }   
            }
        }
    }
    return v;
}


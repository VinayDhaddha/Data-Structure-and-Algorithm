// space compllexity=O(N^2)
// Time compllexity=O(N^2)
vector<string> Solution::prettyJSON(string A) {
    int i=0,indent=0,k;
    string s;
    vector<string> v;
    while(i<A.size()){
        if(A[i]==' ')
            continue;
        else if((A[i]=='{')||(A[i]=='[')){
            for(k=0;k<indent;k++){
                s+="\t";
            }
            indent++;
            s.push_back(A[i]);
            v.push_back(s);
            s="";
            i++;
        }
        else if ((A[i]=='}')||(A[i]==']')){
            indent--;
            for(k=0;k<indent;k++){
                s+="\t";
            }
            s.push_back(A[i]);
            if((i+1)<A.size()){     // boundary condition
                if(A[i+1]==','){
                    s.push_back(A[i+1]);
                    i++;
                }
            }
            v.push_back(s);
            s="";
            i++;
        }
        else{
            for(k=0;k<indent;k++){
                s+="\t";
            }
            while((i<A.size())&&(A[i]!='{')&&(A[i]!='}')&&(A[i]!='[')&&(A[i]!=']')&&(A[i]!=',')){
                s.push_back(A[i]);
                i++;
            }
            if((A[i]==',')){
                s.push_back(A[i]);
                i++;
            }
            v.push_back(s);
            s="";
        }
    }
    return v;
}


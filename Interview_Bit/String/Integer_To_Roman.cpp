// TIME COMPLEXITY-O(N)
// SPACE COMPLEXITY -O(N)

// Important concept
// 1-(IV-1)     I
// 4-8     V
// 9-39    X
// 40-89   L
// 90-(CD-1) C
// 400-(CM-1)  D
// 900-3999  M

void strmul(string &str,int n,char c){  // Fxn to add char from (I,X,C,M) in a string at most 3 times 
    for(int i=0;i<n;i++){
    str+=c;
}
}
string Solution::intToRoman(int A) {
    int m, c, d, l, x, v, i;
    string str;
    m = A / 1000;// no. of 'M' req for integer to convert into roman no.
    strmul(str, m, 'M');// add req 'M' in string
    A %= 1000;// remainder after add M to string 
    if (A >= 900) {str += "CM"; A %= 900;}// if A>=900 came under M range so 
    d = A / 500;// Similar to M
    strmul(str, d, 'D');
    A %= 500;
    if (A >= 400) {str += "CD"; A %= 400; }
    c = A / 100;// Similar to M
    strmul(str, c, 'C');
    A %= 100;
    if (A >= 90) {str += "XC"; A %= 90; }
    l = A / 50;// Similar to M
    strmul(str, l, 'L');
    A %= 50;
    if (A >= 40) { str += "XL"; A %= 40;}
    x = A / 10;// Similar to M
    strmul(str, x, 'X');
    A %= 10;
    if (A >= 9) {str += "IX"; A %= 9;}
    v = A / 5;// Similar to M 
    strmul(str, v, 'V');
    A %= 5;
    i = A;
    if (A == 4) str += "IV";
    else strmul(str, i, 'I');
    return str;
}

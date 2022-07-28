/**
 * @input A : Integer
 * @input B : Integer
 * 
 * @Output Integer
 */
// time complexity=O(max(a,b))
//  space complexity=O(1)
int gcd(int a, int b) {
    if(a==0)            // if anyone of a,b is zero then return another varialbe value
        return b;
    if(b==0)
        return a;
    if(a==b)            // if a==b then return any of a or b 
        return a;
    if(a>b)             //  if a>b then return return gcd(a-b,b) 
        return gcd(a-b,b);
    return gcd(a,b-a);         //if b<a then return return gcd(a,b-a)
}


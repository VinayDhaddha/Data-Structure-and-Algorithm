string Solution::convertToTitle(int A) {
   string s; // To store result (Excel column name)
    int i = 0; // To store current index in str which is result
 
    while (A > 0) {
        // Find remainder
        int rem = A % 26;
 
        // If remainder is 0, then a 'Z' must be there in output
        if (rem == 0) {
            s.push_back('Z');
            A = (A / 26) - 1;
        }
        else // If remainder is non-zero
        {
            s.push_back((rem - 1) + 'A');
            A = A / 26;
        }
    }
    // str[i] = '\0';
 
    // Reverse the string and print result
    reverse(s.begin(), s.end());
    // cout << str << endl;
    return s;
}


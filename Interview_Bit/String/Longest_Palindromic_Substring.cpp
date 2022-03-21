// time complexity=O(N^2)
// space complexity=O(1)

string expand(string str, int low, int high)
{
    int len = str.length();
 
    // run till `str[low.high]` is a palindrome
    while (low >= 0 && high < len && (str[low] == str[high])) {
        low--, high++;        // Expand in both directions
    }
 
    // return palindromic substring
    return str.substr(low + 1, high - low - 1);    /// syntax s.substr(start_ind,size of substring)
}
string Solution::longestPalindrome(string str) {
    // `max_str` stores the maximum length palindromic substring
    // found so far
    int len=str.size();
    string max_str = "", curr_str;
 
    // `max_length` stores the maximum length of palindromic
    // substring found so far
 
    int max_length = 0, curr_length;
 
    // consider every character of the given string as a midpoint and expand
    // in both directions to find maximum length palindrome
 
    for (int i = 0; i < len; i++)
    {
        // find the longest odd length palindrome with `str[i]` as a midpoint
 
        curr_str = expand(str, i, i);
        curr_length = curr_str.length();
 
        // update maximum length palindromic substring if odd length
        // palindrome has a greater length
 
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
 
        // Find the longest even length palindrome with `str[i]` and `str[i+1]`
        // as midpoints. Note that an even length palindrome has two
        // midpoints.
 
        curr_str = expand(str, i, i + 1);
        curr_length = curr_str.length();
 
        // update maximum length palindromic substring if even length
        // palindrome has a greater length
 
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
    }
 
    return max_str;
}


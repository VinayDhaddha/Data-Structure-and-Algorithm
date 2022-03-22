// MOST IMPORTANT QUESTION
int atMaxK(vector<int> &A, int K) {
    int i=0, j=0, len = A.size(), count = 0;
    unordered_map<int, int> umap;

    while( j < len) {
        umap[A[j]] ++;
        while (umap.size() > K) {
            umap[A[i]] --;
            if(not umap[A[i]])
                umap.erase(A[i]);
            i ++;
        }
        j ++;
        // all contiguous subarrays b/w i and j will have at-max K distinct elements
        count += j-i;
    }
    return count;
}
int Solution::solve(vector<int> &A, int B) {
    return (atMaxK(A, B) - atMaxK(A, B-1));
}

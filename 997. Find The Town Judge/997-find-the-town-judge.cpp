#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // If there is only one person, they are the judge by default
        if (n == 1)  
            return 1;

        // Vector to track the trust balance for each person
        vector<int> trust_count(n + 1, 0); 

        for (const auto& relation : trust) {
            int truster = relation[0];
            int trustee = relation[1];
            trust_count[truster]--; // Decrease trust for the truster
            trust_count[trustee]++; // Increase trust for the trustee
        }

        // Check for a person with trust count equal to n - 1
        for (int i = 1; i <= n; ++i) {
            if (trust_count[i] == n - 1) {
                return i;
            }
        }
        
        return -1; // No judge found
    }
};

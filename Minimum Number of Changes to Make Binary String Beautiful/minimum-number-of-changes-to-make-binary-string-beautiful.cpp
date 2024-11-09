#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int changesForPattern1 = 0; // Pattern "010101..."
        int changesForPattern2 = 0; // Pattern "101010..."
        
        for (int i = 0; i < s.size(); i++) {
            // Check against pattern "010101..."
            if (s[i] != (i % 2 == 0 ? '0' : '1')) {
                changesForPattern1++;
            }
            // Check against pattern "101010..."
            if (s[i] != (i % 2 == 0 ? '1' : '0')) {
                changesForPattern2++;
            }
        }
        
        // Return the minimum number of changes needed
        return min(changesForPattern1, changesForPattern2);
    }
};

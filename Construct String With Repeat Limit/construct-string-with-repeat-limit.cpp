#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int r) {
        string result = "";
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> frequencyMap;

        // Count the frequency of each character
        for (char ch : s) {
            frequencyMap[ch]++;
        }

        // Push each character and its frequency into a max-heap
        for (const auto& entry : frequencyMap) {
            maxHeap.push({entry.second, entry.first});
        }

        while (!maxHeap.empty()) {
            auto [freq1, char1] = maxHeap.top();
            maxHeap.pop();

            // Calculate the number of times to add `char1` without exceeding `r`
            int addCount = min(freq1, r);
            result.append(addCount, char1); // Append `char1` up to `r` times

            if (freq1 > addCount) { // If there are more of `char1` left
                if (maxHeap.empty()) { // No other characters to alternate with
                    break;
                }

                // Get the next highest character to break the repetition
                auto [freq2, char2] = maxHeap.top();
                maxHeap.pop();

                result.push_back(char2); // Append `char2` once to break repetition

                // Push back the remaining counts of `char1` and `char2` if any
                maxHeap.push({freq1 - addCount, char1});
                if (freq2 - 1 > 0) {
                    maxHeap.push({freq2 - 1, char2});
                }
            }
        }

        return result;
    }
};

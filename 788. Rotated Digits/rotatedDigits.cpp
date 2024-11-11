class Solution {
public:
    bool isValid(int i) {
        bool hasTransformingDigit = false;
        while (i > 0) {
            int digit = i % 10;
            if (digit == 3 || digit == 4 || digit == 7) {
                return false; // Invalid digit for rotation
            }
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasTransformingDigit = true; // Contains a transforming digit
            }
            i /= 10;
        }
        return hasTransformingDigit; // Return true if there is at least one transforming digit
    }

    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i)) {
                count++;
            }
        }
        return count;
    }
};

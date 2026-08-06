class Solution {
public:
    int smallestNumber(int n, int t) {
        if (n % 10 == 0) {
            return n;
        }
        
        int a = n % 10;
        int b = n / 10;

        int rem;
        if (n <= 9) {
            rem = n % t;
            b = 1;
        }
        else {
            rem = (a * b) % t;
        }

        if (rem != 0) {
            while ((a * b) % t) {
                n++;
                if (n < 10) {
                    a = n;
                    b = 1;
                    continue;
                }
                if (n % 10 == 0) {
                    return n;
                }
                a = n % 10;
                b = n / 10;
            } 
        }
        else {
            return n;
        }
        return n;
    }
};
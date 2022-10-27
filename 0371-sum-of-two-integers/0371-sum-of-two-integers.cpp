class Solution {
public:
    int getSum(unsigned long long a, unsigned long long b) {
        
        while(b) {
            unsigned long long tmp = (a & b);
            tmp *= 2;
            a = a ^ b;
            b = tmp;
        }
        return a;
    }
    
};
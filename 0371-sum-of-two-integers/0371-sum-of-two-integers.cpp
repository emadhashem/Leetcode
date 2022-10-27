class Solution {
public:
    int getSum(unsigned int a, unsigned int b) {
        
        while(b) {
            unsigned int tmp = (a & b);
            tmp *= 2;
            a = a ^ b;
            b = tmp;
        }
        return a;
    }
    
};
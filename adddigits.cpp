#include <iostream>

class Solution {
public:
    int addDigits(int num)
    {
        int sum = 0;

        std::cout << "digits " << num << std::endl;

        if (num < 10) {
            return num;
        }
                
        for (int ii = 0; ; ii++)
        {
            int left = num / 10;
            sum += num - left * 10;

            if (left < 10)
            {
                sum += left;
                break;
            }
            num = left;
        }

        return addDigits(sum);
    }
};

int main(int argc, char **argv)
{
    Solution S;
    int num = (argc > 1)? atoi(argv[1]) : 0;
    int oneDigit;
    
    oneDigit = S.addDigits(num);
    std::cout << "adddigits " << num << " return " << oneDigit << std::endl;
    return 0;
}

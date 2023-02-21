#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    std::vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1)
        return "0";

    std::string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

std::string factorial(int n)
{
    std::string res = "1";
    for (int i = 2; i <= n; i++)
    {
        res = multiply(res, std::to_string(i));
    }
    return res;
}

int main()
{
    std::cout << "Il fattoriale di 10000 è: " << factorial(10000) << std::endl;
    return 0;
}

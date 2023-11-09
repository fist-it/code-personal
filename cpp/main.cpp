#include <string>

std::string createPhoneNumber(const int arr[10])
{
    std::string result = "";
    int count = 0;
    for (int i = 0; i < 15; i++)
    {
        if (i == 0)
        {
            result += '(';
        }
        else if (i == 4)
        {
            result += ')';
        }
        else if (i == 5)
        {
            result += ' ';
        }
        else if (i == 9)
        {
            result += '-';
        }
        else
        {
            result += (char)arr[count];
            count++;
        }
    }
    return(result);
}

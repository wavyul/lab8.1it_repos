#include <iostream>
#include <cstring>

using namespace std;

bool findStr(char* str)
{
    size_t len = strlen(str);
    for (int i = 0; i < len - 1; i++)
        if (str[i] == 'a' && str[i + 1] == 'a' ||
            str[i] == 'b' && str[i + 1] == 'b' ||
            str[i] == 'c' && str[i + 1] == 'c')
            return true;
    return false;
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 2)
        return str;
    char* tmp = new char[len * 3 + 1];
    char* t = tmp;

    tmp[0] = '\0';
    size_t i = 0;

    while (i < len && str[i] != 0)
    {
        if (str[i] == 'a' && str[i + 1] == 'a' ||
            str[i] == 'b' && str[i + 1] == 'b' ||
            str[i] == 'c' && str[i + 1] == 'c')
        {
            strcat_s(t, len * 3 + 1 - (t - tmp), "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    *t = '\0';

    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    char* dest = Change(str);

    findStr(str) ? cout << "'aa or bb or cc' found and will be changed" << endl : cout << "'aa and bb and cc' not found" << endl;

    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}

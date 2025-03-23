#include <iostream>
using namespace std;
class search
{
public:
    int arr[12] = {3, 8, 1, 7, 5, 9, 10, 14, 17, 77, 54, 4};
    void ser(int n)
    {
        bool found = false;
        for (int i = 0; i < 12; i++)
        {
            if (arr[i] == n)
            {
                cout << "Element found at " << i + 1;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Not Found ";
        }
    }
};
int main()
{
    search s;
    int num;
    cout << "Enter the number :";
    cin >> num;
    s.ser(num);
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    double precsicion = 0.000001, error;
    int n;
    float left, right, mid;

    do
    {
        cout << "Enter a natural: ";
        cin >> n;
    } while (n<0);

    left = 0;
    right = n;

    do
    {
        mid = (left + right)/2;
        error = n-mid*mid;

        if (error < 0)
            right = mid;
        else
            left  = mid;

    }while (error > precsicion);

    cout << mid;
}

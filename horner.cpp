// x^4 - 3x^2 + 4x - 6
#include <iostream>
using namespace std;
int horner(int poly[], int n, int x)
{
    int result = poly[0];
    for (int i = 1; i < n; i++)
    {
        result = result * x + poly[i];
    }
    return result;
}
int main()
{
    int poly[] = {1, 0, -3, 4, -6};
    int x = 1;
    int n = sizeof(poly) / sizeof(poly[0]);
    cout << endl
         << endl
         << "Value of polynomial is " << horner(poly, n, x) << endl
         << endl;
    return 0;
}
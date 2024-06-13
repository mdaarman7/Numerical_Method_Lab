// Newton's Forward Interpolation
#include <stdio.h>
int main()
{
    float h, f, p, d, s;
    int i, j, n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the elements of x:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the elements of y:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &y[i]);
    }
    h = x[2] - x[1];
    printf("Please enter the value of x: ");
    scanf("%f", &f);
    p = 1;
    d = y[1];
    s = (f - x[1]) / h;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= (n - i); j++)
        {
            y[j] = y[j + 1] - y[j];
        }
        p = p * (s - i + 1) / i;
        d = d + p * y[1];
    }
    printf("\nWhen x = %.2f, corresponding y = %.2f\n", f, d);
    return 0;
}
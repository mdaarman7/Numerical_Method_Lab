// Lagrange's Interpolation Method
#include <stdio.h>
double Li(int i, int n, double x[n + 1], double X)
{
    int j;
    double prod = 1;
    for (j = 0; j <= n; j++)
    {
        if (j != i)
        {
            prod = prod * (X - x[j]) / (x[i] - x[j]);
        }
    }
    return prod;
}
double Pn(int n, double x[n + 1], double y[n + 1], double X)
{
    double sum = 0;
    int i;
    for (i = 0; i <= n; i++)
    {
        sum = sum + Li(i, n, x, X) * y[i];
    }
    return sum;
}
int main()
{
    int i, n;
    double X; 
    printf("Enter the number of data-points: ");
    scanf("%d", &n);
    n = n - 1;
    double x[n + 1];
    double y[n + 1];
    printf("Enter the x and y data-points:\n");
    for (i = 0; i < n + 1; i++)
    {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("Enter the value of x for which you want the interpolated value of y(x): ");
    scanf("%lf", &X);
    printf("The interpolated value is %.2f", Pn(n, x, y, X));
    return 0;
}
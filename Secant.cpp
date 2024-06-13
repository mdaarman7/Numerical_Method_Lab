// f(x) = x^5 + x^3 + 5 
#include <stdio.h>
#include <math.h>
float quest(float x)
{
    return (x * x * x * x * x) + (x * x * x) + 5;
}
float secant(float x0, float x1, float e, int count1)
{
    int i = 1;
    float Error;
    float x2;
    float f0 = quest(x0);
    float f1 = quest(x1);
    while (i <= count1)
    {
        if (f0 * f1 > 0)
        {
            printf("\n Invalid Guesses");
            return 0;
        }
        else
        {
            fflush(stdin);
            x2 = ((f1 * x0) - (f0 * x1)) / (f1 - f0);
            Error = fabs(x2 - x1);
            if (Error < e)
            {
                return x2;
            }
            else
            {
                printf("\nIteration: %d\tX0: %.4f\tf(X0): %.4f\tX1: %.4f\tf(X1): %.4f\tX2: %.4f", i, x0, f0, x1, f1, x2);
                i++;
                x1 = x2;
                f1 = quest(x1);
            }
        }
    }
}
int main()
{
    float x0, x1, x2, error, root;
    int count;
    printf("\nEnter Initial Guesses:");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter Error Level: ");
    scanf("%f", &error);
    printf("Enter the maximum iteration : ");
    scanf("%d", &count);
    root = secant(x0, x1, error, count);
    printf("\nThe Root is: %.4f", root);
    fflush(stdin);
    return 0;
}
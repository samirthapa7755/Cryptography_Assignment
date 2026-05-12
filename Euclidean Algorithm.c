#include <stdio.h>

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() 
{
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    return 0;
}
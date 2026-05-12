#include <stdio.h>

long long mod_exp(long long base, long long exp, long long mod) 
{
    long long result = 1;

    base = base % mod;

    while (exp > 0) 
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }

    return result;
}

int mod_inverse(int a, int n) 
{
	int x;
    for (x = 1; x < n; x++)
    {
        if ((a * x) % n == 1)
            return x;
    }

    return -1;
}

int main() 
{
    int a, b, n;

    printf("Enter a, b, and modulus n: ");
    scanf("%d %d %d", &a, &b, &n);

    printf("Addition : (%d + %d) mod %d = %d\n",
           a, b, n, (a + b) % n);

    printf("Subtraction : (%d - %d) mod %d = %d\n",
           a, b, n, ((a - b) % n + n) % n);

    printf("Multiplication: (%d * %d) mod %d = %d\n",
           a, b, n, (a * b) % n);

    printf("Exponentiation: %d^%d mod %d = %lld\n",
           a, b, n, mod_exp(a, b, n));

    int inv = mod_inverse(a, n);

    if (inv != -1)
        printf("Modular Inverse of %d mod %d = %d\n", a, n, inv);
    else
        printf("Modular Inverse does not exist.\n");

    return 0;
}
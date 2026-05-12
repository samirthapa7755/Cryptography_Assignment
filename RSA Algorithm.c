#include <stdio.h>

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

long long power(long long base, long long exp, long long mod) 
{
    long long result = 1;

    base = base % mod;

    while (exp > 0) 
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp /= 2;
        base = (base * base) % mod;
    }

    return result;
}

int main() 
{
    int p, q, e;
    long long msg;

    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter prime number q: ");
    scanf("%d", &q);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    printf("n = %d, phi(n) = %d\n", n, phi);

    printf("Enter public key exponent e: ");
    scanf("%d", &e);

    if (gcd(e, phi) != 1) 
    {
        printf("Invalid e! gcd(e, phi) must be 1.\n");
        return 1;
    }

    int d = 1;

    while ((d * e) % phi != 1)
        d++;

    printf("Public Key (e, n) = (%d, %d)\n", e, n);
    printf("Private Key (d, n) = (%d, %d)\n", d, n);

    printf("Enter message to encrypt (number): ");
    scanf("%lld", &msg);

    long long cipher = power(msg, e, n);
    long long decrypted = power(cipher, d, n);

    printf("\nOriginal Message = %lld\n", msg);
    printf("Encrypted Message = %lld\n", cipher);
    printf("Decrypted Message = %lld\n", decrypted);

    return 0;
}
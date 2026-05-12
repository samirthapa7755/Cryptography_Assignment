#include <stdio.h>

long long power(long long base, long long exp, long long mod) 
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

int main() 
{
    long long p, g, a, b, A, B, keyA, keyB;

    printf("Enter public prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root / generator (g): ");
    scanf("%lld", &g);

    printf("Enter Party A private key (a): ");
    scanf("%lld", &a);

    printf("Enter Party B private key (b): ");
    scanf("%lld", &b);

    A = power(g, a, p);   // A = g^a mod p
    B = power(g, b, p);   // B = g^b mod p

    printf("\nParty A public key = %lld\n", A);
    printf("Party B public key = %lld\n", B);

    keyA = power(B, a, p);   // A computes shared secret
    keyB = power(A, b, p);   // B computes shared secret

    printf("Shared Key computed by A = %lld\n", keyA);
    printf("Shared Key computed by B = %lld\n", keyB);

    if (keyA == keyB)
        printf("Key Exchange Successful! Shared Secret = %lld\n", keyA);
    else
        printf("Key Exchange Failed!\n");

    return 0;
}
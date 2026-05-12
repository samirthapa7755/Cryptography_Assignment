#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define F(b,c,d) (((b) & (c)) | ((~b) & (d)))
#define G(b,c,d) (((b) & (d)) | ((c) & (~d)))
#define H(b,c,d) ((b) ^ (c) ^ (d))
#define I(b,c,d) ((c) ^ ((b) | (~d)))

#define ROTL(x,n) (((x) << (n)) | ((x) >> (32 - (n))))

void md5_demo(const char *msg) 
{
    uint32_t A = 0x67452301;
    uint32_t B = 0xEFCDAB89;
    uint32_t C = 0x98BADCFE;
    uint32_t D = 0x10325476;

    printf("MD5 Initial State:\n");

    printf("A = %08X\n", A);
    printf("B = %08X\n", B);
    printf("C = %08X\n", C);
    printf("D = %08X\n", D);

    printf("Auxiliary function results (with initial state):\n");

    printf("F(B,C,D) = %08X\n", F(B, C, D));
    printf("G(B,C,D) = %08X\n", G(B, C, D));
    printf("H(B,C,D) = %08X\n", H(B, C, D));
    printf("I(B,C,D) = %08X\n", I(B, C, D));
}

int main() 
{
    char msg[256];

    printf("Enter message for MD5 demonstration: ");
    fgets(msg, sizeof(msg), stdin);

    printf("Message: %s", msg);
    printf("Length : %lu bytes\n", strlen(msg));

    md5_demo(msg);

    printf("Note: Full MD5 implementation requires complete padding and block processing.\n");

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define F(x,y,z) (((x) & (y)) | ((~x) & (z)))
#define G(x,y,z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))
#define H(x,y,z) ((x) ^ (y) ^ (z))

#define ROTL(x,n) (((x) << (n)) | ((x) >> (32 - (n))))

void md4_print_state(uint32_t A, uint32_t B, uint32_t C, uint32_t D) 
{
    printf("State: A=%08X B=%08X C=%08X D=%08X\n",
           A, B, C, D);
}

int main() 
{
    char msg[256];

    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);

    int len = strlen(msg);

    printf("Message: %s", msg);
    printf("Message length: %d bytes\n", len);

    /* Initialize MD4 state */
    uint32_t A = 0x67452301;
    uint32_t B = 0xEFCDAB89;
    uint32_t C = 0x98BADCFE;
    uint32_t D = 0x10325476;

    printf("Initial MD4 state:\n");

    md4_print_state(A, B, C, D);

    printf("Note: Full MD4 requires padding and block processing.\n");

    printf("MD4 auxiliary functions demonstrated:\n");

    printf("F(A,B,C) = %08X\n", F(A, B, C));
    printf("G(A,B,C) = %08X\n", G(A, B, C));
    printf("H(A,B,C) = %08X\n", H(A, B, C));

    return 0;
}
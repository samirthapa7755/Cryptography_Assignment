#include <stdio.h>
#include <string.h>

// Find modular inverse of determinant
int modInverse(int det) 
{
	int i;
    det = det % 26;

    for (i = 1; i < 26; i++) 
    {
        if ((det * i) % 26 == 1)
            return i;
    }

    return -1;
}

void encrypt(char msg[], int key[2][2], char cipher[]) 
{
	int i;
    int len = strlen(msg);

    // Pad with 'x' if odd length
    if (len % 2 != 0) 
    {
        msg[len] = 'x';
        msg[len + 1] = '\0';
        len++;
    }

    for (i = 0; i < len; i += 2) 
    {
        int a = msg[i] - 'a';
        int b = msg[i + 1] - 'a';

        int c1 = (key[0][0] * a + key[0][1] * b) % 26;
        int c2 = (key[1][0] * a + key[1][1] * b) % 26;

        cipher[i] = c1 + 'a';
        cipher[i + 1] = c2 + 'a';
    }

    cipher[len] = '\0';
}

void decrypt(char cipher[], int key[2][2], char plain[]) 
{
	int i,j;
    int len = strlen(cipher);
    int invKey[2][2];

    // Determinant
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;

    if (det < 0)
        det += 26;

    int detInv = modInverse(det);

    if (detInv == -1) 
    {
        printf("\nKey matrix not invertible. Decryption not possible.\n");
        return;
    }

    invKey[0][0] = ( key[1][1] * detInv) % 26;
    invKey[0][1] = (-key[0][1] * detInv) % 26;
    invKey[1][0] = (-key[1][0] * detInv) % 26;
    invKey[1][1] = ( key[0][0] * detInv) % 26;

    // Fix negatives
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (invKey[i][j] < 0)
                invKey[i][j] += 26;
        }
    }

    // Decrypt
    for (i = 0; i < len; i += 2) 
    {
        int a = cipher[i] - 'a';
        int b = cipher[i + 1] - 'a';

        int p1 = (invKey[0][0] * a + invKey[0][1] * b) % 26;
        int p2 = (invKey[1][0] * a + invKey[1][1] * b) % 26;

        plain[i] = p1 + 'a';
        plain[i + 1] = p2 + 'a';
    }

    plain[len] = '\0';
}

int main() 
{
	int i,j;
    int key[2][2];
    char msg[100], cipher[100], plain[100];

    printf("Enter 2x2 key matrix:\n");

    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter plaintext (lowercase): ");
    scanf("%s", msg);

    encrypt(msg, key, cipher);

    printf("\nEncrypted Text: %s", cipher);

    decrypt(cipher, key, plain);

    printf("\nDecrypted Text: %s", plain);

    return 0;
}
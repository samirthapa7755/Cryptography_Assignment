#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int key);
void decrypt(char text[], int key);

int main() 
{
    char text[100];
    int key, choice;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (shift value): ");
    scanf("%d", &key);

    key = key % 26;   // To handle large keys

    printf("\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        encrypt(text, key);
    else if (choice == 2)
        decrypt(text, key);
    else
        printf("Invalid choice!");

    return 0;
}

void encrypt(char text[], int key) 
{
    int i;

    for (i = 0; text[i] != '\0'; i++) 
    {
        if (isupper(text[i])) 
        {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
        else if (islower(text[i])) 
        {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
    }

    printf("Encrypted text: %s", text);
}

void decrypt(char text[], int key) 
{
    int i;

    for (i = 0; text[i] != '\0'; i++) 
    {
        if (isupper(text[i])) 
        {
            text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        }
        else if (islower(text[i])) 
        {
            text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        }
    }

    printf("Decrypted text: %s", text);
}
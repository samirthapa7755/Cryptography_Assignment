#include <stdio.h>
#include <string.h>

void encryptRailFence(char text[], int key);
void decryptRailFence(char cipher[], int key);

int main() 
{
    char text[100];
    int key;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline from fgets
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key (number of rails): ");
    scanf("%d", &key);

    encryptRailFence(text, key);

    return 0;
}

void encryptRailFence(char text[], int key) 
{
    int len = strlen(text);
    char rail[key][len];
    int i, j;

    for (i = 0; i < key; i++)
    {
        for (j = 0; j < len; j++)
        {
            rail[i][j] = '\n';
        }
    }

    int dir_down = 0, row = 0, col = 0;

    for (i = 0; i < len; i++) 
    {
        if (row == 0 || row == key - 1)
        {
            dir_down = !dir_down;
        }

        rail[row][col++] = text[i];

        if (dir_down)
            row++;
        else
            row--;
    }

    char cipher[100];
    int index = 0;

    for (i = 0; i < key; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] != '\n')
            {
                cipher[index++] = rail[i][j];
            }
        }
    }

    cipher[index] = '\0';

    printf("\nCipher Text: %s\n", cipher);

    decryptRailFence(cipher, key);
}

void decryptRailFence(char cipher[], int key) 
{
    int len = strlen(cipher);
    char rail[key][len];
    int i, j;

    for (i = 0; i < key; i++)
    {
        for (j = 0; j < len; j++)
        {
            rail[i][j] = '\n';
        }
    }

    int dir_down, row = 0, col = 0;

    for (i = 0; i < len; i++) 
    {
        if (row == 0)
            dir_down = 1;

        if (row == key - 1)
            dir_down = 0;

        rail[row][col++] = '*';

        if (dir_down)
            row++;
        else
            row--;
    }

    int index = 0;

    for (i = 0; i < key; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] == '*')
            {
                rail[i][j] = cipher[index++];
            }
        }
    }

    char result[100];

    row = 0;
    col = 0;

    int k = 0;

    for (i = 0; i < len; i++) 
    {
        if (row == 0)
            dir_down = 1;

        if (row == key - 1)
            dir_down = 0;

        result[k++] = rail[row][col++];

        if (dir_down)
            row++;
        else
            row--;
    }

    result[k] = '\0';

    printf("Decrypted Text: %s\n", result);
}
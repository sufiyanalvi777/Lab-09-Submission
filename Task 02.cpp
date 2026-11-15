#include <stdio.h>
#include <string.h>

int main()
{
    char code[100];
    char category[20];
    int i;

    printf("Enter product code: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';

    if (strlen(code) != 8)
    {
        printf("Invalid code: length must be 8.\n");
        return 0;
    }

    if (strchr(code, '-') != code + 3)
    {
        printf("Invalid code: the 4th character must be '-'.\n");
        return 0;
    }

    if (strncmp(code, "ELE", 3) == 0)
    {
        strcpy(category, "Electronics");
    }
    else if (strncmp(code, "GRO", 3) == 0)
    {
        strcpy(category, "Grocery");
    }
    else if (strncmp(code, "CLO", 3) == 0)
    {
        strcpy(category, "Clothing");
    }
    else
    {
        printf("Invalid code: unknown category.\n");
        return 0;
    }

    for (i = 4; i < 8; i++)
    {
        if (!(code[i] >= '0' && code[i] <= '9'))
        {
            printf("Invalid code: last 4 characters must be digits.\n");
            return 0;
        }
    }

    printf("Valid code. Category: %s\n", category);

    return 0;
}

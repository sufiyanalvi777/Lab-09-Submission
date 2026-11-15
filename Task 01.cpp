//Task 01

#include <stdio.h>
#include <string.h>

int main()
{
    char first[256], last[256];
    char badge[43], full[42];

    printf("Enter first name: ");
    fgets(first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0';

    printf("Enter last name: ");
    fgets(last, sizeof(last), stdin);
    last[strcspn(last, "\n")] = '\0';

    if (strlen(first) > 20)
    {
        printf("Error: first name has %zu characters. Maximum allowed is 20.\n",strlen(first));
        return 0;
    }

    if (strlen(last) > 20)
    {
        printf("Error: last name has %zu characters. Maximum allowed is 20.\n", strlen(last));
        return 0;
    }

    strcpy(badge, last);
    strcat(badge, ", ");
    strcat(badge, first);

    strcpy(full, first);
    strcat(full, " ");
    strcat(full, last);

    printf("Badge     : %s\n", badge);
    printf("Full name : %s\n", full);
    printf("Length    : %zu\n", strlen(full));

    return 0;
}

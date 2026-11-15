#include <stdio.h>
#include <string.h>

int main()
{
    char names[5][30];
    char marks[5];
    int i, ch;
    int present = 0, absent = 0;
    int first = 1;

    for (i = 0; i < 5; i++)
    {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);

        /* Clear extra characters if the name is too long. */
        if (strchr(names[i], '\n') == NULL)
        {
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }
        }

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    printf("\nMark attendance (P/A):\n");

    for (i = 0; i < 5; i++)
    {
        do
        {
            printf("%s: ", names[i]);
            scanf(" %c", &marks[i]);

            if (marks[i] != 'P' && marks[i] != 'A')
            {
                printf("Invalid mark. Enter P or A.\n");
            }

        } while (marks[i] != 'P' && marks[i] != 'A');

        if (marks[i] == 'P')
        {
            present++;
        }
        else
        {
            absent++;
        }
    }

    printf("\n--- Attendance Sheet ---\n");

    for (i = 0; i < 5; i++)
    {
        if (marks[i] == 'P')
        {
            printf("%d. %-29s Present\n", i + 1, names[i]);
        }
        else
        {
            printf("%d. %-29s Absent\n", i + 1, names[i]);
        }
    }

    printf("Present: %d, Absent: %d\n", present, absent);
    printf("Absent students: ");

    for (i = 0; i < 5; i++)
    {
        if (marks[i] == 'A')
        {
            if (first == 0)
            {
                printf(", ");
            }

            printf("%s", names[i]);
            first = 0;
        }
    }

    if (absent == 0)
    {
        printf("None");
    }

    printf("\n");

    return 0;
}

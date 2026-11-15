#include <stdio.h>
#include <string.h>

int main()
{
    char rooms[5][5] = {"R101", "R102", "R103", "R104", "R105"};
    char guests[5][100] = {""};
    char room[100], name[100];
    int choice, i, found, ch;

    do
    {
        printf("\n1. Book room\n");
        printf("2. Check out\n");
        printf("3. Show rooms\n");
        printf("4. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1)
        {
            if (feof(stdin))
            {
                return 0;
            }

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            printf("Invalid choice.\n");
            continue;
        }

        /* Clear leftover input before using fgets. */
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }

        if (choice == 1 || choice == 2)
        {
            printf("Enter room number: ");
            fgets(room, sizeof(room), stdin);

            if (strchr(room, '\n') == NULL)
            {
                while ((ch = getchar()) != '\n' && ch != EOF)
                {
                }
            }

            room[strcspn(room, "\n")] = '\0';

            found = -1;

            for (i = 0; i < 5; i++)
            {
                if (strcmp(room, rooms[i]) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("Error: room not found.\n");
            }
            else if (choice == 1)
            {
                if (strcmp(guests[found], "") != 0)
                {
                    printf("Error: %s is already occupied.\n", rooms[found]);
                }
                else
                {
                    printf("Enter guest name: ");
                    fgets(name, sizeof(name), stdin);

                    if (strchr(name, '\n') == NULL)
                    {
                        while ((ch = getchar()) != '\n' && ch != EOF)
                        {
                        }
                    }

                    name[strcspn(name, "\n")] = '\0';

                    if (strcmp(name, "") == 0)
                    {
                        printf("Error: guest name cannot be empty.\n");
                    }
                    else
                    {
                        strcpy(guests[found], name);

                        printf("Room %s booked for %s.\n",
                               rooms[found], guests[found]);
                    }
                }
            }
            else
            {
                if (strcmp(guests[found], "") == 0)
                {
                    printf("Error: %s is already empty.\n", rooms[found]);
                }
                else
                {
                    printf("%s checked out of %s.\n",
                           guests[found], rooms[found]);

                    guests[found][0] = '\0';
                }
            }
        }
        else if (choice == 3)
        {
            for (i = 0; i < 5; i++)
            {
                if (strcmp(guests[i], "") == 0)
                {
                    printf("%s - Empty\n", rooms[i]);
                }
                else
                {
                    printf("%s - %s\n", rooms[i], guests[i]);
                }
            }
        }
        else if (choice == 4)
        {
            printf("Program closed.\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

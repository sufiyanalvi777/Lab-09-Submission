#include <stdio.h>

int main()
{
    FILE *fp;
    char name[50];
    int quantity, i;
    float price, total, grandTotal = 0;

    fp = fopen("sales.txt", "w");

    if (fp == NULL)
    {
        printf("Error: could not open sales.txt for writing.\n");
        return 1;
    }

    for (i = 0; i < 3; i++)
    {
        printf("Enter item %d (name quantity price): ", i + 1);

        if (scanf("%49s %d %f", name, &quantity, &price) != 3)
        {
            printf("Error: invalid input.\n");
            fclose(fp);
            return 1;
        }

        fprintf(fp, "%s %d %.2f\n", name, quantity, price);
    }

    fclose(fp);

    fp = fopen("sales.txt", "r");

    if (fp == NULL)
    {
        printf("Error: could not open sales.txt for reading.\n");
        return 1;
    }

    printf("\n%-15s %5s %10s %10s\n","Item", "Qty", "Price", "Total");

    while (fscanf(fp, "%49s %d %f", name, &quantity, &price) == 3)
    {
        total = quantity * price;
        grandTotal = grandTotal + total;

        printf("%-15s %5d %10.2f %10.2f\n",name, quantity, price, total);
    }

    printf("Grand total: %.2f\n", grandTotal);

    fclose(fp);

    return 0;
}

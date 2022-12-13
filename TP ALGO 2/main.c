#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib.h"

int main()
{
    clock_t start, end;
    printf("\n ..Games of Creating list .. \t \n");
    char *temp;
    int Number;

    int num;
    int n;
    struct Node *head = NULL;
    int option;
    while (1)
    {
        printf("\n ******************************************\n");
        printf("\n *  Linked list doubly :                  *\n");
        printf("\n *    1. Create List                      *\n");
        printf("\n *    2. Remove Node                      *\n");
        printf("\n *    3. Insert                           *\n");
        printf("\n *    4. Display                          *\n");
        printf("\n *    5. SERCH                            *\n");
        printf("\n *    6.fill                             *\n");
        printf("\n *    7.fill RANDOM                      *\n");
        printf("\n *    8. Sorting In Insertion             *\n");
        printf("\n *    9. Sorting In Quick sort            *\n");
        printf("\n *    10. Sorting In Selection             *\n");
        printf("\n *    11. Quit                             *\n");

        printf("\n ******************************************\n");
        printf("\n Choose an option [1-5] : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1: /* create List */

            printf(" Enter the Number of the Data  : ");
            scanf(" %d", &Number);
            head = GetNewNode(Number);
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 2: /* remove */
            printf("Enter the Number of  the Data that you Want To Remove : ");
            scanf("%d", &num);
            removed(num);
            printf("the with the Number %d has been removed. \n", num);
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 3: /* insert */

            printf("Enter the Number of the Data  : ");
            scanf("%d", &Number);
            insert(Number);
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 4:
            display();
            printf("\n Press any key to continue... ");
            getch();
            break;

        case 5:
            printf("Enter the Number of the Data  : ");
            scanf("%d", &Number);
            serch(Number);
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 6:
            printf("Enter the Number of the Data fill it  : ");
            scanf("%d", &Number);
            Fill(Number);
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 7:
            printf("Enter the Number of the ELEMENT fill it  : ");
            scanf("%d", &Number);
            FillRandiom(Number);
            display();
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 8:
            start = clock();
            InseritonSort();
            end = clock();
            display();
            printf("\n le time est %.5f MS ", (double)(end - start));
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 9:
            start = clock();
            quickSort();
            end = clock();
            display();
            printf("\n le time est %.5f MS ", (double)(end - start));
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 10:
            start = clock();
            selectionSort();
            end = clock();
            display();
            printf("\n le time est %.5f MS  ", (double)(end - start));
            printf("\n Press any key to continue... ");
            getch();
            break;
        case 11:
            printf(" \t THE END");
            return 0;
            break;
        default:
            printf("Invalid Option. Please Try again.");
            getch();
        }
    }

    return 0;
}

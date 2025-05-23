/*
Name: Karan KR
Date: 07/101/2025
Description:  Inverted Search Project using data Structures and File Handling.

Sample input: ./a.out file1.txt file2.txt file3.txt

Sampli output: Displaying the menu and performing the operations.
                1.Create database.
                2. Display database.
                3. Search database.
                4. Save database.
                5. Update database.
                Enter your choice: 1
                Database created successfully.
                INPUT: Do you want to Continue? [y / Y]: y
    Display database.
    Enter your choice: 2
    Index   Word    F_count   f_name        w_count
    [7]     [Hai]   [1]     [f1.txt]        [1]
    [8]     [I]     [1]     [f1.txt]        [1]
    [8]     [in]    [1]     [f1.txt]        [1]
    INPUT: Do you want to Continue? [y / Y]: n

*/


#include "header.h"

int main(int argc, char *argv[]) 
{
    // Validate command-line arguments
    Slist *head = NULL;

    //Read and validation Parts
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (strstr(argv[i], ".txt") != NULL)
            {
                FILE *fptr = fopen(argv[i], "r");
                if (fptr != NULL)
                {
                    fseek(fptr, 0, SEEK_END);
                    int file = ftell(fptr);
                    if (file > 0)
                    {  
                        if(head != NULL)
                        {
                            if(check_duplicate(head, argv[i]) == 0)
                            {
                                insert_at_last(&head, argv[i]);
                                printf(YELLOW "INFO: %s file is added to the list.\n",argv[i]);
                            }
                            else
                            {
                                printf(RED"ERROR: %s file is already in the list.\n",argv[i]);
                            } 
                        }
                        else
                        {
                            insert_at_last(&head, argv[i]);
                            printf(YELLOW "INFO: %s file is added to the list.\n",argv[i]);
                        }
                    }
                    else
                    {
                        printf(RED"ERROR: %s file is empty.\n", argv[i]);
                    }
                }
                else
                {
                    printf(RED "ERROR: %s file is not available.\n", argv[i]);
                }
            }
            else
            {
                printf(RED "ERROR: %s file is not in .txt format.\n", argv[i]);
            }
        }
    }
    else
    {
        printf(RED"ERROR: No arguments passed.\n");
        printf(RED"Enter argument passed like this =>  (./a.out file.txt) atleast 1 txt file formate");
    }
    print_list(head);


    hash_t arr[27];
    for(int i = 0; i < 27; i++)
    {
        arr[i].index = i;
        arr[i].ptr = NULL;
    }

    int choice, flag = 0;
    do {
        // Display menu
        printf(GREEN"\n1. Create database\n2. Display database\n3. Search database\n4. Save database\n5. Update database\n");
        printf(WHITE"Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                if(flag == 0)
                {
                    if (Create_database(head, arr) == SUCCESS) 
                    {
                        printf(BLUE"INFO: Database created successfully.\n");
                        flag = 1;
                    }
                    else 
                    {
                        printf(RED"ERROR: Database creation failed.\n");
                    }
                }
                else
                {
                    printf(RED"INFO: Database already created\n");
                }
                break;

            case 2:
                    display_database(arr);
                    break;

            case 3:
                    if (search_database(arr) == DATA_NOT_FOUND)
                    {
                        printf(RED"ERROR: Search Word not found.\n");
                    }
                    else
                    {
                        printf(BLUE"INFO: Search Word found Successfully.\n");
                    }
                    break;

            case 4:
                    if (save_database(arr) == SUCCESS)
                    {
                        printf(BLUE"INFO: Database saved successfully.\n");
                    }
                    else
                    {
                        printf(RED"ERROR: Database save failed.\n");
                    }
                    break;

            case 5:
                   if(update_database(arr, head) == SUCCESS)
                   {
                       printf(BLUE"INFO: Database updated successfully.\n");
                   }
                   else
                   {
                       printf(RED"ERROR: Database update failed.\n");
                   }
                break;
            default:
                printf(RED"ERROR: Invalid choice. Please try again.\n");
                break;
        }
        printf (CYAN "\nINPUT: Do you want to Continue? [y / Y]: " RESET);
        scanf(" %lc", &choice);
	} while ((choice == 'y') || (choice == 'Y'));
}


int check_duplicate(Slist *head, char *arg)
{
    Slist *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->data, arg) == 0)
            return 1;
        temp = temp->link;
    }
    return 0;
}
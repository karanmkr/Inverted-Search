#include "header.h"

// function to save the contents
int save_database(hash_t hash_t[])
{
    char file[20];
    char choice;
    
    // read the backup file from user
    printf("Enter the file name : ");
    scanf("%s", file);

    if(strstr(file, ".txt") == NULL)
    {
        printf(RED"Invalid file format.\n");
        return FAILURE;
    }
    
    FILE *fptr = fopen(file, "w");    // open the file
    
    for (int key = 0; key < 27; key++)
    {
        mainnode_t *temp = hash_t[key].ptr;
        if (temp == NULL)
            continue;
        
        while (temp != NULL)
        {
            fprintf(fptr, "%s", "#");
            fprintf(fptr, "%d;", key);
            fprintf(fptr, "%s;", temp->word);
            fprintf(fptr, "%d;", temp->file_count);
            subnode_t *stemp = temp->sub_link;
            while (stemp != NULL)
            {
                fprintf(fptr, "%s;", stemp->file_name);
                fprintf(fptr, "%d;", stemp->word_count);
                stemp = stemp->slink;
            }
            temp = temp->mlink;
            fprintf(fptr, "%s", "#");
            fprintf(fptr, "%s", "\n");
        }
    }
    fclose(fptr);
    return SUCCESS;
}

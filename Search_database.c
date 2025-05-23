#include "header.h"

int search_database(hash_t arr[])
{
    char word[50];
    int index;

    printf("Enter the word to search: ");
    scanf("%s",word);

    // Calculate index based on the first character of the word
    if (isalpha(word[0]))
    {
        index = isupper(word[0]) ? word[0] - 65 : word[0] - 97;
    }
    else
    {
        index = 26; 
    }

    mainnode_t *temp = arr[index].ptr;
    if (temp == NULL)
    {
        printf(RED"The word '%s' is not found.\n", word);
        return DATA_NOT_FOUND;
    }
  
    while (temp != NULL)
    {
        if (strcmp(temp->word, word) == 0)
        {
            printf(YELLOW"The word '%s' is present in %d files\n", word, temp->file_count);

            subnode_t *stemp = temp->sub_link;
            while (stemp != NULL)
            {
                printf(GREEN"%s -> %d times\n", stemp->file_name, stemp->word_count);
                stemp = stemp->slink;
            }
            return 1; 
        }
        temp = temp->mlink; // Move to the next main node
    }
    printf(RED"The word '%s' is not found.\n", word);
    return DATA_NOT_FOUND; 
}

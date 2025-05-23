#include"header.h"

int display_database(hash_t arr[])
{
    printf(PURPLE"Index\tWord\tF_count\t  F_name\tw_count\t");
    for(int i = 0 ; i < 27; i++)
    {
        if(arr[i].ptr != NULL)
        {
            mainnode_t *temp = arr[i].ptr;
            subnode_t *sub;
                
            while(temp)
            {
                int j = 0;
                
                printf(GREEN"\n%d\t%5s\t%4d\t",i, temp->word, temp->file_count);
                sub = temp->sub_link;
                while(sub)
                {
                    if(j == 0)
                    {
                        printf(GREEN"%8s\t%4d\t\t",sub->file_name,sub->word_count);
                        j = 1;
                    }
                    else
                    {
                        printf(GREEN"%5s\t%4d\t\t",sub->file_name,sub->word_count);
                    }
                    sub=sub->slink;
                }
                temp=temp->mlink;
            }
        }
    }
}
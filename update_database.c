#include"header.h"

int update_database(hash_t *arr, Slist *head)
{
    char str[50];
    printf(CYAN"Entee the saved file name: "RESET);
    scanf("%s", str);

    if(strstr(str, ".txt") == NULL)
    {
        printf(RED"Invalid file format.\n"RESET);
        return FAILURE;
    }

    FILE *fptr = fopen(str, "r");
    if(fptr == NULL)
    {
        printf(RED"File not available.\n"RESET);
        return FAILURE;
    }

    fseek(fptr, 0, SEEK_END);
    int file = ftell(fptr);
    if(file == 0)
    {
        printf(RED"File is empty.\n"RESET);
        return FAILURE;
    }

    fseek(fptr, 0, SEEK_SET);
    char ch;
    char word[50];
    int i = 0;
    if((ch = fgetc(fptr)) != '#')
    {
        printf(RED"Invalid file format.\n"RESET);
        return FAILURE;
    }
    fseek(fptr, -2, SEEK_END);
     ftell(fptr);
    
    if((ch = fgetc(fptr)) != '#')
    {
        printf(RED"Invalid file format.\n"RESET);
        return FAILURE;
    }
    fseek(fptr, 0, SEEK_SET);
    while(fscanf(fptr, "%s", word) != EOF)
    {
        if(strcmp(word, "#") == 0)
        {
            i = 0;
            continue;
        }
        char *token = strtok(word, ";#");
        int pos = atoi(token);
        token = strtok(NULL , ";#");
        char *s_word = token;
        token = strtok(NULL, ";#");
        int f_count = atoi(token);
        for(int i = 0; i < f_count;i++)
        {
            token =  strtok(NULL, ";#");
            char *f_name = token;
            token = strtok(NULL, ";#");
            int w_count = atoi(token);
            if(sl_delete_element(&head, f_name) == SUCCESS)
            {
                printf("%s file is already present in updated file\n",f_name);
            }
            insert_database(arr, pos, s_word, f_name);
        }

    }
    return SUCCESS;
}

int insert_database(hash_t *arr , int index, char *word, char *f_name)
{
    if(arr[index].ptr==NULL)
	{
		mainnode_t *mnew=malloc(sizeof(mainnode_t));
		subnode_t *snew=malloc(sizeof(subnode_t));
		mnew->file_count=1;
		strcpy(mnew->word,word);
		mnew->sub_link=snew;
		mnew->mlink=NULL;
		arr[index].ptr=mnew;
		snew->word_count=1;
		strcpy(snew->file_name, f_name);
		snew->slink=NULL;
	    }
	    else
	    {
		mainnode_t *mtemp=arr[index].ptr;
		mainnode_t *mprev=NULL;
		subnode_t *stemp=NULL;
		subnode_t *sprev=NULL;
		int flag=1,sflag=1;
		while(mtemp)
		{
		    stemp=mtemp->sub_link;
		    if(strcmp(mtemp->word, word)==0)
		    {
			while(stemp)
			{
			    if(strcmp(stemp->file_name, f_name)==0)
			    {
				stemp->word_count++;
				flag=0;
			    }
			    sprev=stemp;
			    stemp=stemp->slink;
			}
			if(flag)
			{
			    mtemp->file_count++;
			    subnode_t *snew=malloc(sizeof(subnode_t));
			    sprev->slink=snew;
			    snew->word_count =1;
			    strcpy(snew->file_name, f_name);
			    snew->slink=NULL;
			    sflag=0;
			}
			mtemp=mtemp->mlink;
		    }
		    else
		    {
			mprev=mtemp;
			mtemp=mtemp->mlink;
		    }

		}
		if(flag && sflag)
		{
		    mainnode_t *mnew=malloc(sizeof(mainnode_t));
		    subnode_t *snew=malloc(sizeof(subnode_t));
		    mprev->mlink=mnew;
		    mnew->file_count=1;
		    strcpy(mnew->word,word);
		    mnew->sub_link=snew;
		    mnew->mlink=NULL;
		    snew->word_count=1;
		    strcpy(snew->file_name, f_name);
		    snew->slink=NULL;
		}
	    }
}
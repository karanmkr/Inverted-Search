#include "header.h"

int Create_database(Slist *filelist, hash_t *arr)
{
	print_list(filelist);
    Slist *temp = filelist;
    while(temp != NULL)
    {
		FILE *fptr= fopen(temp->data, "r");
    	if(fptr == NULL)
    	{
			printf("%s\n",temp->data);
        	printf(RED"File not found\n");
        	return FAILURE;
    	}
		char word[50];
		int index;
	
		while(fscanf(fptr,"%s",word)!=EOF)
		{
	    	if(isalpha(word[0]))
	    	{
            	if(isupper(word[0]))
            	{
                	index = word[0] % 65;
            	}
            	else
            	{
                	index = word[0] % 97;
            	}
	    	}
	    	else
	    	{
		    	index = 26;
	    	}
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
				strcpy(snew->file_name,temp->data);
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
			    	if(strcmp(mtemp->word,word)==0)
			    	{
						while(stemp)
						{
				    		if(strcmp(stemp->file_name,temp->data)==0)
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
			    			strcpy(snew->file_name,temp->data);
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
		    		strcpy(snew->file_name,temp->data);
		    		snew->slink=NULL;
				}
		    }
		}
		temp=temp->link;
    }
    return SUCCESS;
}
#include"header.h"

int insert_at_last(Slist **head , char *data)
{
    Slist *new = malloc(sizeof(Slist));  //To creat a node
    
    if(new == NULL)  //To condition check the node created or not
	return FAILURE;

    //To transfer the data with null
    strcpy(new->data,data);
    new->link = NULL;

    //TO check Head empty or not
    if(*head == NULL)
    {
	    *head = new;
	    return SUCCESS;
    }

    //If head is not empty
    Slist *temp = *head;

    while(temp->link != NULL)  //To find the last node
    {
	    temp = temp->link;
    }


    temp->link = new;   //To copied the data to the node
    return SUCCESS;
}

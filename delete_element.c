#include "header.h"

int sl_delete_element(Slist **head, char *data)
{
    if(*head == NULL)   //To check the head is null or not
        return FAILURE;

    //Take temperary pointers
    Slist *prev = NULL;
    Slist *temp = *head;


    if(strcmp(temp->data , data)== 0) //To check the first node data & given data is same or not
    {
        //If same means to update
        *head = temp->link;
        free(temp);  //Free the temp
        return SUCCESS;
    }

    while(temp != NULL)  //To check the temp reaches upto null
    {
        if(strcmp(temp->data , data) == 0) //To check the data are same or not
        {
            prev->link = temp->link; //previous link update as temp link
            free(temp);  //To free the temp
            return SUCCESS;
        }
        else
        {
            prev = temp;
            temp = temp->link;
        }
    }
    return FAILURE;
}
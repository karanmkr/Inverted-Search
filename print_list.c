#include "header.h"

void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf(RED"\nINFO : List is empty...\n\n");
	}
    else
    {
		printf(PURPLE"\nINFO : List of files\n");
	    while (head)		
	    {
		    printf("%s -> ", head -> data);
		    head = head -> link;
	    }
	    printf("NULL\n\n");
    }
}
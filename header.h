#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS     0
#define FAILURE     -1
#define DATA_NOT_FOUND 2

/* MACRO definitions fo colors */
#define  RED  	 "\033[1;31m"
#define  GREEN	 "\033[1;32m"
#define  BLUE 	 "\033[1;34m"
#define  YELLOW	 "\033[1;33m"
#define  PURPLE	 "\033[1;35m"
#define  CYAN	 "\033[1;36m"
#define  WHITE	 "\033[1;37m"
#define  RESET	 "\033[0m"


typedef struct node
{
    char data[50];
    struct node *link;
}Slist;

typedef struct hash
{
    int index;
    struct mainnode *ptr;
}hash_t;

typedef struct mainnode
{
    int file_count;
    char word[50];
    struct subnode *sub_link;
    struct mainnode *mlink;
}mainnode_t;

typedef struct subnode
{
    int word_count;
    char file_name[50];
    struct subnode *slink;
}subnode_t;


int main(int argc, char *argv[]);
int Read_and_Validate(int argc, char *argv[],Slist *head);
int insert_at_last(Slist **head , char *data);
int check_duplicate(Slist *head, char *arg);
void print_list(Slist *head);

int Create_database(Slist *filelist, hash_t *arr);
int insert_word(mainnode_t **head, char *word, char *file_name);
 int display_database(hash_t arr[]);
int search_database(hash_t arr[]);
int save_database(hash_t hash_t[]);
int Read_and_validate(int argc, char *argv[], Slist *head);
int update_database(hash_t *arr, Slist *head);
int insert_database(hash_t *arr , int index, char *word, char *f_name);
int sl_delete_element(Slist **head, char *data);
#endif

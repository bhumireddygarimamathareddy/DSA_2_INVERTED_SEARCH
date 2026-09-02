#ifndef INVERTED_H
#define INVERTED_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS		1
#define FAILURE		0

#define RESET   "\033[0m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#define BOLD    "\033[1m"

typedef struct file
{
    char f_name[20];
    struct file *link;
}F_node;

typedef struct Sub
{
    int word_count;
    char filename[20];
    struct Sub *sub_link;
}S_node;

typedef struct Main
{
    char word[25];
    int file_count;
    S_node *sub_link;
    struct Main *main_link;
}M_node;

typedef struct Hashtable
{
    int index;
    M_node *H_link;
}hash;

void create_database(hash *HT, F_node *head);
void display_database(hash *HT);
void search_database(hash *HT);
void save_database(hash *HT);
int update_database(hash *HT,F_node **head);

int validate_files(int argc,char *argv[], F_node **head);
int insert_last(F_node **head, char *f_name);
void print_file_list(F_node *head);
int check_duplicates(F_node *head, char *f_name);
int print_filenames(F_node *head);
int get_index(char *word);
void initialize_hash(hash *HT);
S_node *create_sub_node(char *fname);
M_node *create_main_node(char *word);
M_node *search_main_node(M_node *head, char *word);
S_node *search_sub_node(S_node *head, char *fname);

#endif

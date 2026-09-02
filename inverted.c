#include "inverted.h"

/* Function definitions */

int check_duplicate(F_node *head, char *fname)
{
    F_node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->f_name, fname) == 0)
        {
            return SUCCESS;
        }
        temp = temp->link;
    }
    return FAILURE;
}
int insert_at_last(F_node **head, char *f_name)
{
    F_node *ptr = malloc(sizeof(F_node));
    if (ptr == NULL)
    {
        return FAILURE;
    }
    strcpy(ptr->f_name, f_name);
    ptr->link = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        return SUCCESS;
    }
    F_node *temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = ptr;

    return SUCCESS;
}

int print_filenames(F_node *head)
{
    F_node *temp = head;
    printf("The validtated files are:\n");
    while (temp != NULL)
    {
        printf("%s\n", temp->f_name);
        temp = temp->link;
    }

    return SUCCESS;
}
void print_file_list(F_node *head){
    printf("head");
    while(head!=NULL){
        printf(" -> %s",head->f_name);
        head=head->link;
    }
    printf(" ->NULL\n");
}
int validate_files(int argc, char *argv[], F_node **head)
{
    if (argc == 1)
    {
        return SUCCESS;
    }
    int valid_count = 0;
    for (int i = 1; i < argc; i++)
    {
        char *extension = strrchr(argv[i], '.');
        if (extension == NULL || strcmp(extension, ".txt") != 0)
        {
            printf("INFO : %s -> Invalid file extension\n", argv[i]);
            continue;
        }
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("INFO : %s -> File not found\n", argv[i]);
            continue;
        }
        fseek(fp, 0, SEEK_END);
        if (ftell(fp) == 0)
        {
            printf("INFO : %s -> File is empty\n", argv[i]);
            fclose(fp);
            continue;
        }
        fclose(fp);
        if (check_duplicate(*head, argv[i]) == SUCCESS)
        {
            printf("INFO : %s -> Duplicate file\n", argv[i]);
            continue;
        }
        if (insert_at_last(head, argv[i]) == SUCCESS)
        {
            valid_count++;
        }
        else
        {
            printf("ERROR : Unable to insert %s\n", argv[i]);
            return FAILURE;
        }
    }
    if (valid_count == 0)
    {
        printf("ERROR : No valid input files found\n");
        return FAILURE;
    }
    return SUCCESS;
}
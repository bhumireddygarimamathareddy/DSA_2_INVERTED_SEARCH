#include "inverted.h"
//getting the index for the each word in the files
int get_index(char *word)
{
    if(word[0] >= 'A' && word[0] <= 'Z')
        return word[0] - 'A';

    else if(word[0] >= 'a' && word[0] <= 'z')
        return word[0] - 'a';

    else
        return 26;
}
//initializing the hash table
void initialize_hash(hash *HT)
{
    for(int i = 0; i < 27; i++)
    {
        HT[i].index = i;
        HT[i].H_link = NULL;
    }
}
// Creating the Sub Node 
S_node *create_sub_node(char *fname)
{
    S_node *new = malloc(sizeof(S_node));

    if(new == NULL)
        return NULL;

    strcpy(new->filename, fname);
    new->word_count = 1;
    new->sub_link = NULL;
    return new;
}
/* Creating Main Node */
M_node *create_main_node(char *word)
{
    M_node *new = malloc(sizeof(M_node));

    if(new == NULL)
        return NULL;

    strcpy(new->word, word);
    new->file_count = 1;
    new->sub_link = NULL;
    new->main_link = NULL;

    return new;
}
/* Search Main Node */
M_node *search_main_node(M_node *head, char *word)
{
    while(head != NULL)
    {
        if(strcmp(head->word, word) == 0)
            return head;
        head = head->main_link;
    }

    return NULL;
}
/* Search Sub Node */
S_node *search_sub_node(S_node *head, char *fname)
{
    while(head != NULL)
    {
        if(strcmp(head->filename, fname) == 0)
            return head;

        head = head->sub_link;
    }

    return NULL;
}
/*  Main Create Database function logic starts from here */
void create_database(hash *HT, F_node *head)
{
    int flag = 0;
    for (int i = 0; i < 27; i++)
    {
        if (HT[i].H_link != NULL)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
         printf("INFO : Database already exists. Again create  is not possible\n");
         return;
    }
    char word[100];
    while(head != NULL)
    {
        FILE *fp = fopen(head->f_name, "r");

        if(fp == NULL)
        {
            head = head->link;
            continue;
        }
        while(fscanf(fp, "%s", word) != EOF)
        {
            int index = get_index(word);

            M_node *m_temp = search_main_node(HT[index].H_link, word);
            /* if Words not present */
            if(m_temp == NULL)
            {
                M_node *m_new = create_main_node(word);
                S_node *s_new = create_sub_node(head->f_name);
                m_new->sub_link = s_new;
                if(HT[index].H_link == NULL)
                {
                    HT[index].H_link = m_new;
                }
                else
                {
                    M_node *temp = HT[index].H_link;

                    while(temp->main_link != NULL)
                    {
                        temp = temp->main_link;
                    }

                    temp->main_link = m_new;
                }
            }
            /* if Words are already present means  */
            else
            {
                S_node *s_temp = search_sub_node(m_temp->sub_link, head->f_name);

                /* File not present */
                if (s_temp == NULL)
                {
                    S_node *s_new = create_sub_node(head->f_name);

                    if (m_temp->sub_link == NULL)
                    {
                        m_temp->sub_link = s_new;
                    }
                    else
                    {
                        S_node *last = m_temp->sub_link;

                        while (last->sub_link != NULL)
                            last = last->sub_link;

                        last->sub_link = s_new;
                    }

                    m_temp->file_count++;
                }
                /* File already present */
                else
                {
                    s_temp->word_count++;
                }
            }
        }

        fclose(fp);
        head = head->link;
    }

    printf("Database created successfully\n");
}
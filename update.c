#include "inverted.h"

int update_database(hash *HT, F_node **head)
{
    char file_name[100];
    printf("Enter the backup file : ");
    scanf("%99s", file_name);
    /* Validate extension */
    int dot = 0;
    for (int i = 0; file_name[i] != '\0'; i++)
    {
        if (file_name[i] == '.')
            dot++;
    }
    if (dot != 1)
    {
        printf("INFO : Backup file should contain only one .txt\n");
        return FAILURE;
    }
    char *ext = strrchr(file_name, '.');

    if (ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf("ERROR : Invalid extension\n");
        return FAILURE;
    }
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("ERROR : File not found\n");
        return FAILURE;
    }
    /* Validate backup format */
    char first = fgetc(fp);
    fseek(fp, -1, SEEK_END);
    char last = fgetc(fp);
    if (last == '\n')
    {
        fseek(fp, -2, SEEK_END);
        last = fgetc(fp);
    }
    if (first != '#' || last != '#')
    {
        printf("ERROR : Invalid backup file\n");
        fclose(fp);
        return FAILURE;
    }
    rewind(fp);
    int index, file_count;
    char word[50];
    while (fscanf(fp, "#%d;%[^;];%d;", &index, word, &file_count) == 3)
    {
        M_node *m_temp = search_main_node(HT[index].H_link, word);
        /* Word not present */
        if (m_temp == NULL)
        {
            M_node *m_new = create_main_node(word);
            m_new->file_count = file_count;

            S_node *last_sub = NULL;

            for (int i = 0; i < file_count; i++)
            {
                char fname[50];
                int count;

                fscanf(fp, "%[^;];%d;", fname, &count);

                S_node *s_new = create_sub_node(fname);
                s_new->word_count = count;

                if (m_new->sub_link == NULL)
                {
                    m_new->sub_link = s_new;
                    last_sub = s_new;
                }
                else
                {
                    last_sub->sub_link = s_new;
                    last_sub = s_new;
                }
            }

            fscanf(fp, "#\n");

            if (HT[index].H_link == NULL)
            {
                HT[index].H_link = m_new;
            }
            else
            {
                M_node *temp = HT[index].H_link;

                while (temp->main_link != NULL)
                    temp = temp->main_link;

                temp->main_link = m_new;
            }
        }
        /* Word already present */
        else
        {
            for (int i = 0; i < file_count; i++)
            {
                char fname[50];
                int count;

                fscanf(fp, "%[^;];%d;", fname, &count);

                S_node *s_temp = search_sub_node(m_temp->sub_link, fname);

                if (s_temp == NULL)
                {
                    S_node *s_new = create_sub_node(fname);
                    s_new->word_count = count;

                    S_node *last = m_temp->sub_link;

                    while (last->sub_link != NULL)
                        last = last->sub_link;

                    last->sub_link = s_new;
                    m_temp->file_count++;
                }
            }

            fscanf(fp, "#\n");
        }
    }

    fclose(fp);
    printf("Database updated successfully\n");
    return SUCCESS;
}
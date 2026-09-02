#include "inverted.h"
void display_database(hash *HT)
{
    printf(BOLD CYAN);
    printf("---------------------------------------------------------------------\n");
    printf("%-8s %-15s %-10s %-15s %-10s\n",
           "INDEX", "WORD", "FILECOUNT", "FILENAME", "WORDCOUNT");
    printf("---------------------------------------------------------------------\n");
    printf(RESET);
    for (int i = 0; i < 27; i++)
    {
        M_node *m_temp = HT[i].H_link;
        while (m_temp != NULL)
        {
            S_node *s_temp = m_temp->sub_link;
            printf(YELLOW "%-8d " RESET GREEN  "%-15s " RESET BLUE   "%-10d " RESET MAGENTA "%-15s " RESET   RED    "%-10d\n" RESET,
                  HT[i].index,m_temp->word,m_temp->file_count,s_temp->filename,s_temp->word_count);
            s_temp = s_temp->sub_link;
            while (s_temp != NULL)
            {
                printf("%-8s %-15s %-10s " MAGENTA "%-15s " RESET RED "%-10d\n" RESET,"", "", "",
                        s_temp->filename,s_temp->word_count);
                s_temp = s_temp->sub_link;
            }
            printf("\n");
            m_temp = m_temp->main_link;
        }
    }
    printf("---------------------------------------------------------------------\n");
}
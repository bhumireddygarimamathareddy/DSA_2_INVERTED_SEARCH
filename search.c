#include "inverted.h"
void search_database(hash *HT)
{
    char word[50];
    printf("Enter the word to be  search:");
    scanf("%s",word);
    int index=get_index(word);
    M_node *M_temp=HT[index].H_link;
    while(M_temp!=NULL){
        if(strcmp(M_temp->word,word)==0){
            printf("Word %s is present in %d file(s)\n",M_temp->word,M_temp->file_count);
            S_node *s_temp=M_temp->sub_link;
            while(s_temp!=NULL){
                printf("InFile : %-10s  WordCount : %dtime(s)\n", s_temp->filename,s_temp->word_count);
                s_temp=s_temp->sub_link;
            }
            return ;
        }
        M_temp=M_temp->main_link;
    }
    printf("The word %s is not present in the fiels\n",word);

}

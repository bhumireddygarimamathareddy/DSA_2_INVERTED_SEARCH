#include "inverted.h"

void save_database(hash *HT)
{
    char filename[50];
    printf("Enter the file name:\n");
    scanf("%s",filename);
    int count=0;
    for(int i=0;filename[i]!='\0';i++){
          if(filename[i]=='.'){
            count++;
          }
    }
    if(count!=1){
        printf("ERROR:Extension is should be only .txt\n"); 
    }
    char *ext = strrchr(filename, '.');
    if (ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf("ERROR: Extension is not valid. Enter a .txt file\n");
        return;
    }
    if(ext==filename){
        return ;
    }
    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        printf("INFO:Error occured to open the file\n");
        return ;
    }
    for(int i=0;i<27;i++){
        if(HT[i].H_link==NULL){
            continue;
        }
        M_node *M_temp=HT[i].H_link;
            while(M_temp!=NULL){
                S_node *s_temp=M_temp->sub_link;
                fprintf(fp,"#%d;%s;%d;",HT[i].index,M_temp->word,M_temp->file_count);
            while(s_temp!=NULL){
                fprintf(fp,"%s;%d",s_temp->filename,s_temp->word_count);
                s_temp=s_temp->sub_link; 
              }
              fprintf(fp,"#\n");
              M_temp=M_temp->main_link;
            }

    }
    fclose(fp);

}   

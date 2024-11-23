/*
 * A program to read a file of cricketers with Name, Age, number of matches, average_score
 * 1. Create a array of structure to hold records of 20 players
 * 2. use qsort() to arrange them in ascending order of average_score 
 * Note --> store "data.txt" in the same folder
 */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_MAX 100
#define RECORDS 20
#define RECORD_DELIMITER ","


typedef struct _player{
    char name[RECORDS];
    int age, n_matches, avg_score;
    
} Player;

Player player_rec[RECORDS] = {0};

void createPlayerRecord(char* line, int rec)
{
    //printf("line %d --  %s\n", rec ,line);  
    char* token = strtok(line, RECORD_DELIMITER);
    char i ='1';
    //printf("token  %s\n", token);
    while(token)
    {
        //printf("token fdadfsjk %s\n", token);
        // printf("%c fdd\n", i);
        switch(i){
           
            case '1':
                strcpy( player_rec[rec].name, token); i++;
                break;
            case '2':
                player_rec[rec].age = atoi(token); i++;
                break;
            case '3':
                player_rec[rec].n_matches = atoi(token);i++;
                break;
            case '4':    
                  player_rec[rec].avg_score = atoi(token);i++;
                break;            
            

        }
        token = strtok(NULL, RECORD_DELIMITER);
        //printf("i amfmafds dfs - %s\n", player_rec[rec].name);

    }
    

}

void printSortedResult(int records)
{
    for (int i =0 ; i < records;i++)
    {
        printf("%s , %d, %d, %d \n", player_rec[i].name, player_rec[i].age, player_rec[i].n_matches,player_rec[i].avg_score );
    }
}
int compare_avg_runs(const void* r1, const void* r2)
{
    return (*(Player*)r1).avg_score - (*(Player*)r2).avg_score;
}

void readData()
{

    FILE *fptr;
    char line[LINE_MAX];    
    int records = 0;

    fptr = fopen("data.txt", "r");
    
    if(fptr)
    {
        while (fgets(line, LINE_MAX, fptr) != NULL && records <RECORDS) {
            createPlayerRecord(line, records++);
        }
        fclose(fptr);
    }
    qsort(player_rec,records,sizeof(Player), compare_avg_runs);
    printSortedResult(records);


}



int main(void)
{
    readData();
    printf("hello I am here\n");
}
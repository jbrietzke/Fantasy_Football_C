//
//  functions.c
//  Fantasy_Football
//
//  Created by Jackson Brietzke on 7/5/17.
//  Copyright © 2017 Jackson Brietzke. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Header.h"

int PLAYERS = 2;
void read_players(Player rbs[10])
{
    printf("We are reading runningbacks\n");
    FILE *ptr_file;
    //char buf[1000];
    char first_name[15];
    char last_name[15];
    char nfl_team[4];
    char plays_in[4];
    int ch = 0;
    ptr_file =fopen("./runningback_seed.txt","r");
    if (!ptr_file)
    {
        printf("The file is not found\n");
        return;
    }
    for (int x=0; x < PLAYERS; x++) {
        last_name[0] = '\0';
        first_name[0] = '\0';
        nfl_team[0] = '\0';
        plays_in[0] = '\0';
        ch = getc(ptr_file);
        while (ch != '\n' && ch != EOF) {
            while(ch != ' ' && ch != EOF && ch != '\n' && ch != '\t')
            {
                append(first_name, 15, ch);
                ch = getc(ptr_file);
            }
            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file); // ch is at an empty space so we get the next character
            while(ch != ' ' && ch != EOF && ch != '\n' && ch != '\t')
            {
                append(last_name, 15, ch);
                ch = getc(ptr_file);
            }
            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
            while(ch != ' ' && ch != EOF && ch != '\n' && ch != '\t')
            {
                append(nfl_team, 4, ch);
                ch = getc(ptr_file);
            }
            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
            while(ch != ' ' && ch != EOF && ch != '\n' && ch != '\t')
            {
                append(plays_in, 4, ch);
                ch = getc(ptr_file);
            }
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            while ((ch == ' ' || ch == '\t') && ch != EOF) ch = getc(ptr_file);
//            printf("What is my name: %s,%s\n", first_name, last_name);
            strcpy(rbs[x].first_name, first_name);
            strcpy(rbs[x].last_name, last_name);
            strcpy(rbs[x].nfl_team, nfl_team);
            sscanf(plays_in, "%d", &rbs[x].plays_involved_in);
        }
    }
    
    
    //while (fgets(buf,1000, ptr_file)!=NULL)
        //printf("%s\n",buf);
    
    fclose(ptr_file);
    return;
}
int  append(char*s, size_t size, char c) {
    if(strlen(s) + 1 >= size) {
        return 1;
    }
    unsigned long len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
    return 0;
}

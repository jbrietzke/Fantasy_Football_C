//
//  Header.h
//  Fantasy_Football
//
//  Created by Jackson Brietzke on 7/5/17.
//  Copyright © 2017 Jackson Brietzke. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <stdbool.h>
typedef struct Player
{
    char first_name[15];
    char last_name[15];
    char nfl_team[4];
    int plays_involved_in, games_played, run_plays,
        rush_yds, rush_tds, pass_targets, pass_recs,
        rec_yds, rec_tds, fumbles, interceptions;
    bool available;
} Player;

void read_players(Player rbs[10]);
int  append(char*s, size_t size, char c);
#endif /* Header_h */

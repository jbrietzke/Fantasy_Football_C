//
//  main.c
//  Fantasy_Football
//
//  Created by Jackson Brietzke on 7/5/17.
//  Copyright © 2017 Jackson Brietzke. All rights reserved.
//

#include <stdio.h>
#include "./Header.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Player running_backs[10];
    read_players(running_backs);
    for (int x=0; x < 2; x++) {
        printf("Player name: %s,%s,%s,%d\n", running_backs[x].first_name, running_backs[x].last_name, running_backs[x].nfl_team, running_backs[x].plays_involved_in);
    }
        return 0;
}

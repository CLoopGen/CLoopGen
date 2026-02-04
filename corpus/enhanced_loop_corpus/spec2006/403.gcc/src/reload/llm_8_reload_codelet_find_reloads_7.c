#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matches[30];
extern int goal_alternative_matched[30];
extern char goal_alternative_win[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < noperands && i < 30; i += 2) {
        if (!goal_alternative_win[i] && goal_alternative_matches[i] >= 0) {
            goal_alternative_matched[goal_alternative_matches[i]] = i;
        }
        if (i + 1 < noperands && !goal_alternative_win[i+1] && goal_alternative_matches[i+1] >= 0) {
            goal_alternative_matched[goal_alternative_matches[i+1]] = i + 1;
        }
    }
}

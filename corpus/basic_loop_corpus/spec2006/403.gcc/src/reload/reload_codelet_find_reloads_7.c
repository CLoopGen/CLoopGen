#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matches[30];
extern int goal_alternative_matched[30];
extern char goal_alternative_win[30];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < noperands; i++)
    if (!goal_alternative_win[i] && goal_alternative_matches[i] >= 0)
        goal_alternative_matched[goal_alternative_matches[i]] = i;

}

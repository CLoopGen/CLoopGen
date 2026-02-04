#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern char goal_alternative_match_win[30];
extern char goal_alternative_win[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < noperands; j++) {
    for (i = 0; i <= j; i++) {
        goal_alternative_win[i] |= goal_alternative_match_win[i];
    }
}
}

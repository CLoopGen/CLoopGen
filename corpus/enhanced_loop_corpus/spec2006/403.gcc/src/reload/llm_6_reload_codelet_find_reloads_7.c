#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matches[30];
extern int goal_alternative_matched[30];
extern char goal_alternative_win[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_matched[30];
    for (int j = 0; j < 30; j++)
        temp_matched[j] = goal_alternative_matched[j];
    for (i = 0; i < noperands; i++) {
        if (!goal_alternative_win[i] && goal_alternative_matches[i] >= 0) {
            int idx = goal_alternative_matches[i];
            temp_matched[idx] = i;
        }
    }
    for (i = 0; i < 30; i++)
        goal_alternative_matched[i] = temp_matched[i];
}

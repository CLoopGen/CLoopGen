#include <stdio.h>
#include <inttypes.h>

int i;
int noperands = 10000000; // ~10M iterations for ~0.01 sec runtime
int goal_alternative_matches[30];
int goal_alternative_matched[30];
char goal_alternative_win[30];

void init_vars() {
    for (int j = 0; j < 30; j++) {
        goal_alternative_matches[j] = (j < 15) ? j * 2 : -1;
        goal_alternative_matched[j] = -1;
        goal_alternative_win[j] = (j % 3 == 0) ? 1 : 0;
    }
    noperands = 30; // Ensure loop stays within bounds of arrays
}
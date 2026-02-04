#include <stdio.h>
#include <inttypes.h>

int i;
int noperands = 30;
char goal_alternative_match_win[30];
char goal_alternative_win[30];

void init_vars() {
    for (int j = 0; j < 30; j++) {
        goal_alternative_match_win[j] = (char)(j * 7);
        goal_alternative_win[j] = (char)(j * 11);
    }
}
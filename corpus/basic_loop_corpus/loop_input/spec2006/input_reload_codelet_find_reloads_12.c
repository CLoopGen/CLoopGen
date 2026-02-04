#include <stdio.h>
#include <inttypes.h>

int i;
int noperands = 30;
int goal_alternative_matched[30];

void init_vars() {
    i = 0;
    noperands = 30;
    for (int j = 0; j < 30; j++) {
        goal_alternative_matched[j] = -1;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int stat[15];
int i;
int best;

void init_vars() {
    for (int idx = 0; idx < 15; idx++) {
        stat[idx] = rand();
    }
    i = 0;
    best = 0;
}
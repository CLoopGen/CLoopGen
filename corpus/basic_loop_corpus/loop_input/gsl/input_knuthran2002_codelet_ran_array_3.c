#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

long aa[200];
long ran_x[137];
unsigned int i;
unsigned int j;

void init_vars() {
    i = 37;
    j = 100;

    for (int idx = 0; idx < 200; idx++) {
        aa[idx] = rand() % ((1L << 30));
    }
    for (int idx = 0; idx < 137; idx++) {
        ran_x[idx] = rand() % ((1L << 30));
    }
}
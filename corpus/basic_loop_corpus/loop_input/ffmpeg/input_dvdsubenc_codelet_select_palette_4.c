#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int hits[33];
int i;
int j;
int selected[4];

void init_vars() {
    for (int idx = 0; idx < 33; idx++) {
        hits[idx] = rand() % 1000;
    }
    for (int idx = 0; idx < 4; idx++) {
        selected[idx] = idx % 33;
    }
    i = 0;
    j = 0;
}
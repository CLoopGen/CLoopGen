#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int counts[17];
int prefixes[18];
int i;

void init_vars() {
    for (int j = 0; j < 17; j++) {
        counts[j] = rand() % 1000;
    }
    for (int j = 0; j < 18; j++) {
        prefixes[j] = rand() % 1000;
    }
    i = 0;
}
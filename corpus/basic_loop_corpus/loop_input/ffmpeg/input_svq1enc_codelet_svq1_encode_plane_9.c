#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int level;
double threshold[6];

void init_vars() {
    threshold[5] = 1000000.0;
    for (int i = 0; i < 5; i++) {
        threshold[i] = 0.0;
    }
    level = 4;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

int max;
int energy[15];
int i;

void init_vars() {
    max = 0;
    for (int idx = 0; idx < 15; idx++) {
        energy[idx] = rand() % 200 - 100; // Values between -100 and 99
    }
    i = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int counts[17] = {0};
int codes[17] = {0};

void init_vars() {
    for (int j = 0; j < 17; j++) {
        counts[j] = rand() % 100 + 1;
        codes[j] = rand() % 100;
    }
}
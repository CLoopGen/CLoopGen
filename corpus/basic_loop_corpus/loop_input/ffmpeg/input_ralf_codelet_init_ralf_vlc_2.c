#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int counts[17];
int i;

void init_vars() {
    for (int j = 0; j < 17; j++) {
        counts[j] = 0;
    }
    i = 0;
}
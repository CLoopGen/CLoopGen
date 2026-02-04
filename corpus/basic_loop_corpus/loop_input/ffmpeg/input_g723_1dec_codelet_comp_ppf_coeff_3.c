#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int temp1;
int energy[5];

void init_vars() {
    i = 0;
    temp1 = 0;
    for (int idx = 0; idx < 5; idx++) {
        energy[idx] = rand() % 100;
    }
}
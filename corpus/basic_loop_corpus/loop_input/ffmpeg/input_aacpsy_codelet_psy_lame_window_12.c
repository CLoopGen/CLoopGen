#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int attacks[9];
int i;

void init_vars() {
    for (int j = 0; j < 9; j++) {
        attacks[j] = rand() % 2;
    }
    i = 0;
}
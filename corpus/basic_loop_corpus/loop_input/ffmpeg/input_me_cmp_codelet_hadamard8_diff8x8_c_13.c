#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int temp[64];
int sum;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        temp[idx] = rand() % 100 - 50;
    }
    i = 0;
    sum = 0;
}
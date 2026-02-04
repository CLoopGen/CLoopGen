#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t nops[10000];
int i;
int nop_sum;

void init_vars() {
    for (int j = 0; j < 10000; j++) {
        nops[j] = (uint16_t)(j * 31);
    }
    i = 0;
    nop_sum = 0;
}
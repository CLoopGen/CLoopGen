#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ccr_buf[80];
int iter;
int i;
int max;

void init_vars() {
    iter = 4; 
    i = 0;
    max = 0;

    for (int idx = 0; idx < 80; idx++) {
        ccr_buf[idx] = rand() % 200 - 100;
    }
}
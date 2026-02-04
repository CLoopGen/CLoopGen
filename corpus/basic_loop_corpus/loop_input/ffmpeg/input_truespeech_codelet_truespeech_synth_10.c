#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t ts_decay_35_64[8] = {1000, -2000, 3000, -4000, 5000, -6000, 7000, -8000};
int i;
int t[8];
int16_t *ptr1;

void init_vars() {
    ptr1 = (int16_t*)malloc(8 * sizeof(int16_t));
    if (!ptr1) {
        exit(1);
    }
    for (int j = 0; j < 8; j++) {
        ptr1[j] = (int16_t)(j * 100);
    }
}
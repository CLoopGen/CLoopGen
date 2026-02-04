#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t ts_decay_3_4[8] = {0};
int i = 0;
int t[8] = {0};
int16_t *ptr1 = NULL;

void init_vars() {
    ptr1 = (int16_t*)malloc(8 * sizeof(int16_t));
    if (!ptr1) {
        exit(1);
    }
}
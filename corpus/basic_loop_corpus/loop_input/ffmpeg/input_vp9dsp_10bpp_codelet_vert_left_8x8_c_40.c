#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint16_t *top;
int i;
uint16_t ve[7];
uint16_t vo[7];

static uint16_t top_data[1 << 17]; // 128KB of data (1<<17 elements)

void init_vars() {
    if (!top) {
        top = top_data;
    }
    for (int j = 0; j < (1 << 17); j++) {
        top[j] = rand() & 0xFFFF;
    }
    for (int j = 0; j < 7; j++) {
        ve[j] = 0;
        vo[j] = 0;
    }
    i = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t range_min = 1000;
uint32_t value = 2048;
int len = 1 << 20; // Approximately 1 million iterations for ~0.01 sec runtime
char bits[1 << 20];
int i;

void init_vars() {
    range_min = 1000;
    value = (1 << 20) / 2;
    len = 1 << 20;
    for (int j = 0; j < len; j++) {
        bits[j] = 'X';
    }
    i = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t range_min = 1000;
uint32_t value = 5000;
int len = 2097152; // ~8MB of data, tuned for ~0.01 sec runtime on modern CPU
char bits[33];
int i;

void init_vars() {
    range_min = 1000;
    value = 5000;
    len = 2097152;
    if (len > 32) len = 32; // ensure we don't overflow bits array which is size 33
    for (int j = 0; j < 33; j++) {
        bits[j] = '1';
    }
    i = 0;
}
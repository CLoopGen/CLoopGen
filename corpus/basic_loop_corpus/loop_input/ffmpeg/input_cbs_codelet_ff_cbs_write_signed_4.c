#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 32;
int32_t value = 0x80000000U;
char bits[33];

int i;

void init_vars() {
    width = 32;
    value = 0x12345678U;
    for (int j = 0; j < 33; j++) {
        bits[j] = '0';
    }
    i = 0;
}
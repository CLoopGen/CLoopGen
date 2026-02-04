#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 256;
uint32_t value = 0xABCDEF12;
int b;
char bits[33];
int i;

void init_vars() {
    width = 32;
    value = 0x87654321;
    b = 0;
    i = 0;
    for (int j = 0; j < 33; j++) {
        bits[j] = '0';
    }
    bits[32] = '\0';
}
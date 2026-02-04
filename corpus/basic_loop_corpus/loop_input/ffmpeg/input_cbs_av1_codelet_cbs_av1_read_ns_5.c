#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t v = 0xdeadbeef;
int w;
char bits[33];
int i;

void init_vars() {
    w = 32;
    v = 0x12345678;
    for (i = 0; i < 33; i++) {
        bits[i] = 'X';
    }
    i = 0;
}
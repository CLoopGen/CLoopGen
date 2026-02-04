#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t zeroes;
char bits[65];
int i;

void init_vars() {
    zeroes = 64;
    for (i = 0; i < 65; i++) {
        bits[i] = 'X';
    }
    i = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t zeroes;
uint32_t bits_value;
char bits[65];
int i;
int j;

void init_vars() {
    zeroes = 64;
    bits_value = 0xDEADBEEF;
    i = 0;
    j = 0;
    for (int k = 0; k < 65; k++) {
        bits[k] = 'X';
    }
}
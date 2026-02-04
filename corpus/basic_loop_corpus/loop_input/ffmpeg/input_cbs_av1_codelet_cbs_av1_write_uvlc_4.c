#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t v = 0xABCD1234;
int zeroes = 32;
char bits[65];
int i = 0;
int j = 0;

void init_vars() {
    v = 0xABCD1234;
    zeroes = 32;
    i = 0;
    for (int k = 0; k < 65; k++) {
        bits[k] = '\0';
    }
}
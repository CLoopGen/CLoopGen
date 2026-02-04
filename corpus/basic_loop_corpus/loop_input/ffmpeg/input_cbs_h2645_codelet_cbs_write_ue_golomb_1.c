#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 16777216; // 16M elements, ~0.01 sec on modern CPU
char bits[65];
int i;

void init_vars() {
    len = 64; // Ensure it does not exceed the actual array size of bits
    for (i = 0; i < len; i++) {
        bits[i] = 0;
    }
    i = 0;
}
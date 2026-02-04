#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width = 20971520; // ~20 million elements for ~0.01 sec runtime (adjustable)
uint32_t magnitude = 0xABCDEF01;
char bits[33];
int i;

void init_vars() {
    width = 32;
    magnitude = 0xABCDEF01;
    i = 0;
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *bitlens;
int zlcount;
int blcounts[32];
int syms[8192];

void init_vars() {
    bitlens = (uint8_t*)calloc(256, sizeof(uint8_t));
    if (!bitlens) exit(1);

    for (int i = 0; i < 256; i++) {
        bitlens[i] = rand() % 32;
    }

    zlcount = 0;

    for (int i = 0; i < 32; i++) {
        blcounts[i] = 0;
    }

    for (int i = 0; i < 8192; i++) {
        syms[i] = -1;
    }
}
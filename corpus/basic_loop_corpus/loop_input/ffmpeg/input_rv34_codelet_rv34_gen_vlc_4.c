#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int codes[17];
uint16_t cw[1296];
uint8_t bits2[1296];
int realsize;

void init_vars() {
    realsize = 1296;

    for (int j = 0; j < 17; j++) {
        codes[j] = j * 100;
    }

    for (int j = 0; j < 1296; j++) {
        bits2[j] = j % 17;
    }
}
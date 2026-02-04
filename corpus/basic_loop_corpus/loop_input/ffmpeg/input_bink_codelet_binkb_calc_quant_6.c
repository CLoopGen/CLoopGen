#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t bink_scan[64];
uint8_t inv_bink_scan[64];
int i;

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        bink_scan[idx] = (uint8_t)(63 - idx);
    }
    for (int idx = 0; idx < 64; idx++) {
        inv_bink_scan[idx] = 0;
    }
    i = 0;
}
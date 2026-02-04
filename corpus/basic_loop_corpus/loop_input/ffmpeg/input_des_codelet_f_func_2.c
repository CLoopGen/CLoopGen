#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t S_boxes_P_shuffle[8][64];
uint32_t r;
uint64_t k;
int i;
uint32_t out;

void init_vars() {
    for (int box = 0; box < 8; box++) {
        for (int idx = 0; idx < 64; idx++) {
            S_boxes_P_shuffle[box][idx] = rand() % 0xFFFFFFFF;
        }
    }
    r = rand() % 0xFFFFFFFF;
    k = rand() % 0xFFFFFFFFFFFFFFFF;
}
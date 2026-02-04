#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t thd_layout[13];
int chanmap;
int i;
uint64_t layout;

void init_vars() {
    for (int j = 0; j < 13; j++) {
        thd_layout[j] = (uint64_t)(j + 1) * 0x12345678ULL;
    }
    chanmap = 0x1FFF;
    i = 0;
    layout = 0;
}
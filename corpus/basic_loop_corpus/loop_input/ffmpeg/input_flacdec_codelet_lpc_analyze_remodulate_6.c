#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *decoded;
int order = 0;
int len = 0;
int i = 0;
int ebps = 0;
unsigned int sigma = 0;

void init_vars() {
    len = 67108864; // ~256MB of data (67M elements * 4 bytes per uint32_t)
    order = 0;
    ebps = 1;
    sigma = 0;

    decoded = (uint32_t*)malloc(len * sizeof(uint32_t));
    if (!decoded) {
        exit(1);
    }

    for (int idx = 0; idx < len; idx++) {
        decoded[idx] = (uint32_t)(idx & 0xFFFFF);
    }
}
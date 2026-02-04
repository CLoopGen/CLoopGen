#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint32_t max = 1048576; // 1MB of data, approximates 0.01 sec runtime
uint32_t *cntsum;
uint16_t *freqs1;
uint16_t *freqs2;
uint16_t *cnts;
uint8_t *dectable;
uint32_t y;
uint32_t e;
uint32_t g;
uint32_t q;

void init_vars() {
    // Allocate and initialize cntsum
    cntsum = (uint32_t*)calloc(1, sizeof(uint32_t));
    if (!cntsum) exit(1);

    // Allocate arrays based on max + 1 to prevent out-of-bounds access
    freqs1 = (uint16_t*)calloc(max + 1, sizeof(uint16_t));
    freqs2 = (uint16_t*)calloc(max + 1, sizeof(uint16_t));
    cnts = (uint16_t*)calloc(max + 1, sizeof(uint16_t));
    if (!freqs1 || !freqs2 || !cnts) exit(1);

    // Initialize cnts with non-zero values to ensure meaningful computation
    for (uint32_t i = 0; i <= max; i++) {
        cnts[i] = (uint16_t)((i * 739) % 3000); // pseudo-random small counts
    }

    // dectable size: worst-case q can be up to ((sum of cnts) >> 7) + 1
    // We conservatively estimate size as (max * 3000) >> 7 plus safety margin
    size_t dectable_size = ((max * 3000) >> 7) + 256;
    dectable = (uint8_t*)calloc(dectable_size, sizeof(uint8_t));
    if (!dectable) exit(1);
}
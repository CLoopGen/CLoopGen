#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t max = 1048576; // 1M elements for ~0.01 sec runtime
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
    cntsum = (uint32_t*)calloc(1, sizeof(uint32_t));
    freqs1 = (uint16_t*)calloc(max + 1, sizeof(uint16_t));
    freqs2 = (uint16_t*)calloc(max + 1, sizeof(uint16_t));
    cnts = (uint16_t*)calloc(max + 1, sizeof(uint16_t));
    dectable = (uint8_t*)calloc(2 * max, sizeof(uint8_t)); // generously sized to prevent OOB

    for (uint32_t i = 0; i <= max; i++) {
        cnts[i] = (i % 100) + 1; // small positive values to control growth of c
    }
}
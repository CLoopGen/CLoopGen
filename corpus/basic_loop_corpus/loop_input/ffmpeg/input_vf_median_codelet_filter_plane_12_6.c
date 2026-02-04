#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int src_linesize;
int width;
int jobnr;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint16_t *srcp;

#define COARSE_SIZE (256 * 1024 * 1024)  // ~256MB for coarse (larger binning)
#define FINE_SIZE   (256 * 1024 * 1024)  // ~256MB for fine
#define SRC_SIZE    (8 * 1024 * 1024)    // ~8MB source data

void init_vars() {
    width = 4096;
    radiusV = 3;
    jobnr = 1;
    src_linesize = width;

    uint16_t *src_data = (uint16_t*)calloc(SRC_SIZE, sizeof(uint16_t));
    ccoarse = (uint16_t*)calloc(COARSE_SIZE, sizeof(uint16_t));
    cfine = (uint16_t*)calloc(FINE_SIZE, sizeof(uint16_t));

    for (size_t i = 0; i < SRC_SIZE; i++) {
        src_data[i] = rand() & ((1 << 13) - 1);  // 13-bit values as implied by shift logic
    }

    srcp = src_data;
}
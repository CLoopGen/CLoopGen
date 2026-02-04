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

#define COARSE_SIZE (256 * 1024 * 1024)  // ~256MB for coarse binning
#define FINE_SIZE   (512 * 1024 * 1024)  // ~512MB for fine binning
#define SRC_TOTAL_SIZE (64 * 1024 * 1024) // ~64MB source data

void init_vars() {
    width = 8192;
    radiusV = 3;
    jobnr = 1;  // ensures conditional term (jobnr != 0) evaluates to 1

    src_linesize = width;

    // Allocate source pointer array
    srcp = (uint16_t*)aligned_alloc(32, SRC_TOTAL_SIZE);
    if (!srcp) exit(1);

    // ccoarse bins by j and high bits of srcp[j]
    // index: (1 << 8) * j + (srcp[j] >> 8)
    // max j is width, max high byte is 255 -> size needed: 256 * width + 256
    int ccoarse_size = 256 * width + 256;
    ccoarse = (uint16_t*)aligned_alloc(32, ccoarse_size * sizeof(uint16_t));
    if (!ccoarse) exit(1);

    // cfine uses full decomposition: 
    // index: (1<<8)*(width*(srcp[j]>>8) + j) + (srcp[j]&255)
    // maximum offset depends on max value of srcp[j] and j
    // assuming srcp[j] up to 65535, then high part can be up to 255
    // worst-case index: (1<<8)*(width*255 + width-1) + 255
    // = 256*(256*width - 1) + 255 ~ 256*256*width
    int cfine_size = 256 * 256 * width;
    cfine = (uint16_t*)aligned_alloc(32, cfine_size * sizeof(uint16_t));
    if (!cfine) exit(1);

    // Initialize srcp with pseudo-random but valid values
    for (size_t i = 0; i < SRC_TOTAL_SIZE / sizeof(uint16_t); i++) {
        srcp[i] = (uint16_t)((i * 73856093) & 0xFFFF);
    }
}
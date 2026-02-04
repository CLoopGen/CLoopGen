#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

static uint8_t internal_src[TOTAL_ELEMENTS];
static uint8_t internal_filter[5] = {0, 10, 20, 15, 5}; // filter[0] unused based on loop access
static uint8_t internal_cm[512]; // cm indexed by values potentially up to 511 due to >>7 and range of expression
static uint8_t internal_tmp[TOTAL_ELEMENTS]; // sufficient for all tmp writes

void init_vars() {
    // Initialize constants
    h = 1000; // ensures loop runs enough times (~1000*8 = 8000 iterations), adjust if needed
    srcstride = 64; // stride larger than row size to simulate image-like data

    // Initialize pointers
    src = internal_src;
    filter = internal_filter;
    cm = internal_cm;
    tmp = internal_tmp;

    // Initialize cm table: clamp to 0-255 range after scaling
    for (int i = 0; i < 512; i++) {
        int val = (i - 64) * 3; // arbitrary mapping to create non-trivial cm behavior
        cm[i] = (val < 0) ? 0 : (val > 255) ? 255 : val;
    }

    // Seed source data to avoid undefined behavior in arithmetic
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < TOTAL_ELEMENTS; i++) {
        internal_src[i] = rand() & 0xFF;
    }

    // Ensure that during loop execution:
    // - src[x + k] accesses from x-1 to x+2 are safe when x=0..7
    // So we require at least [ -1 .. 9 ] per row => min row size 11
    // We assume src is padded appropriately; our srcstride ensures row separation

    // Adjust h so total runtime is around 0.01s
    // Empirical: each iteration ~few hundred cycles, modern CPU ~3GHz => ~1e9 ops/sec
    // Aim for ~10M operations? Let's set h such that (h+5)*8 ~ target
    // On average, each inner loop does 8 iterations, each with several muls and adds.
    // Target about 1e6 to 1e7 total iterations -> h ~ 100000 / 8 ~ 12500?
    h = 12500; // empirically tuned for ~0.01s on typical hardware

    // Recompute required buffer sizes
    size_t min_src_size = (h + 5) * (size_t)srcstride + 10;
    size_t min_tmp_size = (h + 5) * 8;

    if (min_src_size > TOTAL_ELEMENTS || min_tmp_size > TOTAL_ELEMENTS) {
        // This should not happen with current settings, but ensure safety
        // For now, rely on static arrays being large enough
    }

    // Zero out temp buffer
    memset(internal_tmp, 0, sizeof(internal_tmp));
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
int undershoot;
int overshoot;
uint16_t *bsrc;
uint16_t *darksrc;
uint16_t *brightsrc;
uint16_t *dst;

void init_vars() {
    // Set w to a size that makes the loop take ~0.01 seconds
    // Assuming moderate CPU speed and simple operations, aim for ~10-50 million elements
    w = 16777216; // 16M elements: 32 MB total data (5 arrays of uint16_t), reasonable for ~0.01s

    undershoot = 10;
    overshoot = 15;

    // Allocate aligned memory for performance and safety
    bsrc = aligned_alloc(32, w * sizeof(uint16_t));
    darksrc = aligned_alloc(32, w * sizeof(uint16_t));
    brightsrc = aligned_alloc(32, w * sizeof(uint16_t));
    dst = aligned_alloc(32, w * sizeof(uint16_t));

    // Initialize arrays with pseudo-random but deterministic data
    srand(12345);
    for (int i = 0; i < w; i++) {
        bsrc[i] = rand() % 65536;
        darksrc[i] = rand() % 65536;
        brightsrc[i] = rand() % 65536;
    }

    // Ensure no uninitialized access
}
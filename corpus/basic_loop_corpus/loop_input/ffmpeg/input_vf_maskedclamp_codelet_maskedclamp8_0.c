#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
int undershoot;
int overshoot;
uint8_t *bsrc;
uint8_t *darksrc;
uint8_t *brightsrc;
uint8_t *dst;

void init_vars() {
    // Set problem size to achieve around 0.01 seconds runtime
    // Based on typical performance, w ~ 64M operations gives ~0.01s on modern CPUs
    w = 64 * 1024 * 1024; // 64 million elements

    undershoot = 10;
    overshoot = 15;

    // Allocate memory for arrays
    bsrc = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));
    darksrc = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));
    brightsrc = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));
    dst = (uint8_t*)aligned_alloc(32, w * sizeof(uint8_t));

    if (!bsrc || !darksrc || !brightsrc || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with pseudo-random data based on seed
    srand(0);
    for (int i = 0; i < w; i++) {
        bsrc[i] = rand() % 256;
        darksrc[i] = rand() % 256;
        brightsrc[i] = rand() % 256;
    }

    // Initialize dst to zero
    memset(dst, 0, w * sizeof(uint8_t));
}
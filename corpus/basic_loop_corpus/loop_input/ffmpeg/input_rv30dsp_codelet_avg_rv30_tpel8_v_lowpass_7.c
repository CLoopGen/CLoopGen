#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int C1;
int C2;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024)  // ~64 MB of total data to target ~0.01 sec runtime
#define STRIDE 1024                  // Sufficiently large stride to avoid cache conflicts
#define HEIGHT 65536                 // Adjust height so that w * sizeof(uint8_t) * height ~ DATA_SIZE

static uint8_t dst_data[HEIGHT][STRIDE];
static uint8_t src_data[HEIGHT + 9][STRIDE];  // +9 to cover src[-1] to src[8*stride] safely
static uint8_t cm_data[256];

void init_vars() {
    // Initialize constants
    C1 = 12;
    C2 = 24;
    w = STRIDE;  // process one full row per iteration
    dstStride = 1;
    srcStride = 1;
    i = 0;

    // Initialize pointers
    dst = &dst_data[0][0];
    src = &src_data[1][0];  // Point src such that src[-1] is valid (src_data[0][-1] safe)

    cm = cm_data;

    // Initialize cm lookup table: map signed 8-bit offset range to clipped 0-255
    for (int j = 0; j < 256; j++) {
        cm_data[j] = (uint8_t)((j * j) % 256);  // arbitrary non-trivial mapping
    }

    // Initialize src data to prevent undefined behavior in computation
    for (int y = 0; y < HEIGHT + 9; y++) {
        for (int x = 0; x < STRIDE; x++) {
            src_data[y][x] = rand() & 0xFF;
        }
    }

    // Initialize dst data
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < STRIDE; x++) {
            dst_data[y][x] = rand() & 0xFF;
        }
    }
}
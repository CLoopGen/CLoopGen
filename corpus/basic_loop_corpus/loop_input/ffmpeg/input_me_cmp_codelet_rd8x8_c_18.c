#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *scantable;
int16_t (*temp);
int i;
int last;
int run;
int bits;
int level;
int start_i;
int esc_length;
uint8_t *length;

#define DATA_SIZE (1 << 20)  // 1MB of data

void init_vars() {
    // Allocate and initialize scantable: maps index to coefficient index
    scantable = malloc(DATA_SIZE * sizeof(uint8_t));
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        scantable[idx] = (uint8_t)(idx % 256);
    }

    // Allocate and initialize temp: holds quantized DCT coefficients
    temp = malloc(DATA_SIZE * sizeof(int16_t));
    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        // Simulate AC coefficients: mostly zero, occasional non-zero
        temp[idx] = (idx % 32 == 0) ? ((int16_t)((rand() % 200) - 100)) : 0;
    }

    // Allocate and initialize length table: VLC code lengths for (run, level)
    length = malloc(256 * 128 * sizeof(uint8_t));  // [run][level], run up to 255, level offset by 64
    for (int r = 0; r < 256; r++) {
        for (int l = 0; l < 128; l++) {
            length[r * 128 + l] = (uint8_t)((r + l) % 32 + 1);  // realistic-looking variable length
        }
    }

    // Initialize scalar variables
    start_i = 0;
    last = DATA_SIZE;
    run = 0;
    bits = 0;
    level = 0;
    esc_length = 16;  // escape code length for out-of-range levels
}
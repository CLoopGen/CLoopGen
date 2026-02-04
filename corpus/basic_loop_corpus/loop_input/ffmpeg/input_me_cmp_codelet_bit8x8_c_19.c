#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

void init_vars() {
    const int data_size = 1 << 20; // 1MB of input data

    // Allocate and initialize scantable: maps index to a byte value within valid range
    scantable = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    for (int idx = 0; idx < data_size; idx++) {
        scantable[idx] = rand() % 256;
    }

    // temp is a pointer to an array of int16_t with indices determined by scantable values
    temp = (int16_t*)calloc(256, sizeof(int16_t));
    for (int idx = 0; idx < 256; idx++) {
        temp[idx] = (rand() % 255) - 128; // typical DCT coefficient range
    }

    // length table: (run, level) -> bits, run in [0,6], level in [1,127]
    length = (uint8_t*)calloc(6 * 128 + 128, sizeof(uint8_t)); // index: run*128 + level
    for (int run = 0; run < 6; run++) {
        for (int lvl = 1; lvl < 128; lvl++) {
            length[run * 128 + lvl] = (rand() % 10) + 1;
        }
    }
    // Extended levels beyond typical run handling
    for (int lvl = 1; lvl < 128; lvl++) {
        length[5 * 128 + lvl] = (rand() % 10) + 1;
    }

    // Set loop control variables
    start_i = 0;
    last = data_size; // matches scantable size
    run = 0;
    bits = 0;
    level = 0;
    esc_length = 16; // typical escape code bit length
}
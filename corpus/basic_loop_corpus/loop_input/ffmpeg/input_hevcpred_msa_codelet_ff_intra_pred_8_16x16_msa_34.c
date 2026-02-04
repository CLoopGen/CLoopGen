#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
uint8_t *left;
int bottom_left_size;
uint32_t pix;

#define DATA_SIZE (1 << 20) // 1MB

static uint8_t data_buffer[DATA_SIZE];

void init_vars() {
    bottom_left_size = 0; // Ensure valid range: 0 <= bottom_left_size < 16
    pix = 0xdeadbeef;
    left = data_buffer;
}

// Ensure the loop accesses within bounds:
// Access occurs at: left + 16 + bottom_left_size + i
// Max i is 15 (loop: i < 16 - bottom_left_size, step 4)
// So max offset = 16 + bottom_left_size + 15 = 31 + bottom_left_size
// With bottom_left_size in [0,15], max offset = 46
// Our buffer is 1MB, so it's safe.
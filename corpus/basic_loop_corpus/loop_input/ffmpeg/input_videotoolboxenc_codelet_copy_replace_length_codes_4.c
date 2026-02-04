#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t length_code_size = 1 << 20; // 1MB of data for ~0.01 sec runtime
uint8_t size_buf[1 << 20];
size_t box_len = 0;
size_t i = 0;

void init_vars() {
    // Initialize size_buf with pseudo-random but deterministic data
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < length_code_size; idx++) {
        size_buf[idx] = (uint8_t)(rand() % 256);
    }
    // Ensure first few bytes don't create overflow issues in practice
    // since we're shifting and OR'ing into box_len (treated as big-endian decode)
    box_len = 0;
    i = 0;
}
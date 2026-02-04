#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *top;
uint8_t *filtered_top;

static uint8_t *top_data;
static uint8_t *filtered_top_data;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    top_data = (uint8_t *)aligned_alloc(32, data_size);
    filtered_top_data = (uint8_t *)aligned_alloc(32, data_size);

    if (!top_data || !filtered_top_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        top_data[idx] = rand() & 0xFF;
    }

    top = top_data + 1; // Adjust so that top[i-1] at i=0 accesses top_data[0]
    filtered_top = filtered_top_data + 1;

    // Ensure boundaries: loop uses i from (2*32-2)=62 down to 0, and accesses i+1, i, i-1
    // So we need valid data from index -1 to 63 in the top array view
    // With top = top_data + 1, index -1 maps to top_data[0], index 63 maps to top_data[64]
    // Thus we require at least 65 bytes in top_data, which is satisfied by 64MB
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

char *row[6];
int i;

void init_vars() {
    // Allocate 512KB of data to ensure loop runtime around 0.01 seconds
    const size_t total_size = 512 * 1024;
    char *data_block = (char *)calloc(total_size, sizeof(char));
    
    if (!data_block) return;

    // Initialize each row pointer to point to a 85KB segment (approx equal)
    size_t chunk = total_size / 6;
    for (int idx = 0; idx < 6; idx++) {
        row[idx] = &data_block[idx * chunk];
    }
}
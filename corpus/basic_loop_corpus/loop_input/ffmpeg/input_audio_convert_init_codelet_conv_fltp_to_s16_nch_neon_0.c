#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t **src;
int channels;

static uint8_t *data_pool[256];
static uint8_t *pointers[65]; // up to index 64

void init_vars() {
    // Allocate a total of approximately 1MB - 2MB of data to ensure loop runs ~0.01s
    const size_t total_data_size = 1 << 20;
    const size_t chunk_size = total_data_size / 64;
    for (int i = 0; i < 64; i++) {
        data_pool[i] = malloc(chunk_size);
        if (!data_pool[i]) {
            exit(1);
        }
    }

    // Initialize src pointer array
    for (int i = 0; i < 65; i++) {
        pointers[i] = (i < 3 || i >= 64) ? NULL : data_pool[i];
    }
    src = pointers;

    // Initialize channels to a value below the loop start
    channels = 0;
}
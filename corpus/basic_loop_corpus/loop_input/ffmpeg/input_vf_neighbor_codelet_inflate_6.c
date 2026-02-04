#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *p1;
int width;
int threshold;
uint8_t *coordinates[8];
int x;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static uint8_t *data_pool = NULL;

void init_vars() {
    width = 65536; // Sufficiently large for measurable execution time
    threshold = 50;
    x = 0;
    i = 0;

    // Allocate large contiguous block to simulate realistic data size
    data_pool = (uint8_t*)calloc(DATA_SIZE, sizeof(uint8_t));
    if (!data_pool) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = data_pool;
    p1 = data_pool + width;

    // Initialize coordinate pointers to point into different regions
    for (int idx = 0; idx < 8; idx++) {
        coordinates[idx] = data_pool + width * (idx + 2);
        // Ensure each coordinate array has at least 'width' elements
        for (int j = 0; j < width; j++) {
            coordinates[idx][j] = rand() % 256;
        }
    }

    // Initialize p1 and dst arrays
    for (int j = 0; j < width; j++) {
        p1[j] = rand() % 256;
        dst[j] = 0;
    }
}
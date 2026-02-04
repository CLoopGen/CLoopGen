#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int max;
uint8_t *yuvClusters;
int *points;
int bias;

void init_vars() {
    max = 10 * 1024 * 1024;  // Approximate size to run loop for ~0.01 seconds
    size_t total_size = max * 24;

    yuvClusters = (uint8_t *)calloc(total_size, sizeof(uint8_t));
    points = (int *)malloc(total_size * sizeof(int));

    if (!yuvClusters || !points) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        yuvClusters[idx] = (uint8_t)(idx % 256);
    }
}

// End of file
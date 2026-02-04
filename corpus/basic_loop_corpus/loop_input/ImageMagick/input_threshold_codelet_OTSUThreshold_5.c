#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data per array to target ~0.01s runtime

double *myu;
double *omega;
double *probability;
ssize_t i;

void init_vars() {
    // Allocate large arrays to ensure loop takes measurable time (~64M elements)
    myu = (double*)calloc(DATA_SIZE, sizeof(double));
    omega = (double*)calloc(DATA_SIZE, sizeof(double));
    probability = (double*)calloc(DATA_SIZE, sizeof(double));

    if (!myu || !omega || !probability) {
        // In a real scenario we might handle allocation failure, but here just rely on OS to manage
        exit(1);
    }

    // Initialize probability array with non-zero values to make computation meaningful
    for (size_t idx = 1; idx < DATA_SIZE; idx++) {
        probability[idx] = (double)(rand() % 100) / 1000.0; // Small random probabilities
    }
}
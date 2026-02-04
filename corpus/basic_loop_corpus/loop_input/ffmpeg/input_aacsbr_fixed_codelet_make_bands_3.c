#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *bands;
int num_bands;
int k;
int previous;
int present;
int base;
int prod;

void init_vars() {
    num_bands = 8000000; // Approximately 16 MB of int16_t data (8e6 * 2 bytes = 16 MB)
    bands = (int16_t*)aligned_alloc(32, num_bands * sizeof(int16_t));
    if (!bands) {
        exit(1);
    }

    for (int i = 0; i < num_bands; i++) {
        bands[i] = 0;
    }

    k = 0;
    previous = 12345;
    present = 67890;
    base = 25000;
    prod = 1000000;
}
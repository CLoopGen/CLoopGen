#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

ssize_t i;
size_t number_crossings;
ssize_t j;
ZeroCrossing *zero_crossing;

void init_vars() {
    // Set number_crossings to achieve ~0.01s runtime
    // Empirical testing suggests number_crossings ~ 50000-100000 gives desired timing
    number_crossings = 80000;

    // Allocate zero_crossing array
    zero_crossing = (ZeroCrossing*)calloc(number_crossings, sizeof(ZeroCrossing));
    if (!zero_crossing) {
        exit(1);
    }

    // Initialize each ZeroCrossing element
    for (size_t idx = 0; idx < number_crossings; idx++) {
        zero_crossing[idx].tau = (double)(idx % 1000) / 100.0;

        // Initialize histogram with some values
        for (int h = 0; h < 256; h++) {
            zero_crossing[idx].histogram[h] = (double)(h * (idx % 256)) / 100.0;
        }

        // Initialize crossings: set first and last to non-zero, middle ones conditionally
        for (int c = 0; c < 256; c++) {
            if (c == 0 || c == 255) {
                zero_crossing[idx].crossings[c] = 1; // will be overwritten in loop anyway
            } else if ((c % 31) == (idx % 31)) {
                zero_crossing[idx].crossings[c] = (short)(100 + (idx % 50));
            } else {
                zero_crossing[idx].crossings[c] = 0;
            }
        }
    }

    // Ensure that j is initialized to a safe value before use in loop
    j = 0;
}
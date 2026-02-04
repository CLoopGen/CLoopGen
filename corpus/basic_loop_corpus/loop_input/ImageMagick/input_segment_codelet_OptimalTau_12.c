#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

ssize_t *histogram;
ssize_t i = 0;
ssize_t j;
ZeroCrossing *zero_crossing;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of input data (adjustable)
    histogram = (ssize_t*)calloc(256, sizeof(ssize_t));
    zero_crossing = (ZeroCrossing*)calloc(data_size, sizeof(ZeroCrossing));

    if (!histogram || !zero_crossing) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (ssize_t idx = 0; idx < 256; ++idx) {
        histogram[idx] = idx * 3;
    }

    i = 0; // Ensure `i` is within allocated bounds of zero_crossing
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

double *histogram;
ssize_t i;
ssize_t start;

static double histogram_buffer[256];

void init_vars() {
    for (int idx = 0; idx < 256; idx++) {
        histogram_buffer[idx] = (idx < 100) ? 0.0 : (idx * 1.5);
    }
    histogram = histogram_buffer;
    i = 0;
    start = 0;
}
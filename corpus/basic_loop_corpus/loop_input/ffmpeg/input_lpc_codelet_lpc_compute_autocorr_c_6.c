#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *data;
int len;
int i;
int j;
double sum;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(double);  // ~512MB of data to ensure loop takes ~0.01s
    data = (double*)aligned_alloc(32, len * sizeof(double));
    if (!data) {
        exit(1);
    }

    for (int idx = 0; idx < len; ++idx) {
        data[idx] = 1.0 + (idx % 100) * 0.01;
    }

    j = 100;  // Ensure valid access: i-j and i-j+1 must be in bounds
    i = 0;
    sum = 0.0;

    // Adjust len to ensure i+1 < len when i += 2 and starting from j-1
    len = ((len - j) / 2) * 2 + j;  // Make sure upper bound aligns with step 2
    if (len > (int)(64 * 1024 * 1024 / sizeof(double))) {
        len = 64 * 1024 * 1024 / sizeof(double);
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float FFTSample;

FFTSample *data;
int n;
int i;

void init_vars() {
    size_t data_size_bytes = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime
    n = (data_size_bytes / sizeof(FFTSample)) - 1; // Ensure index i-2 is valid for last access

    if ((n % 2) == 1) n--; // Ensure n is even so that i <= n with i+=2 starting at 3 doesn't overflow

    data = (FFTSample*)aligned_alloc(32, (n + 1) * sizeof(FFTSample));
    
    if (!data) {
        exit(1);
    }

    for (int idx = 0; idx <= n; idx++) {
        data[idx] = (FFTSample)(rand() % 1000) / 10.0f;
    }
}
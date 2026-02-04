#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t count;
ssize_t bestk;
ssize_t i;
unsigned char *o;
unsigned char unordered[16];

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    count = 67108864; // 64 million elements to target ~0.01 sec runtime
    bestk = 0;
    o = (unsigned char *)malloc(count * sizeof(unsigned char));
    if (!o) {
        exit(1);
    }

    for (size_t idx = 0; idx < count; idx++) {
        o[idx] = rand() % 16; // ensure o[i] is in [0,15] to index unordered safely
    }

    memset(unordered, 0, 16);

    // Warm up loop measurement to estimate initialization cost
    for (i = bestk; i < (ssize_t)count && i < 1000000; i++) {
        unordered[o[i]] = 1;
    }

    gettimeofday(&end, NULL);
    long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    if (elapsed < 10000) {
        // If warm-up was too fast, scale up count to get better timing
        double factor = 10000.0 / (elapsed + 1);
        size_t new_count = (size_t)(count * factor);
        if (new_count > count && new_count <= 268435456) { // Cap at ~256MB
            free(o);
            count = new_count;
            o = (unsigned char *)malloc(count * sizeof(unsigned char));
            if (!o) {
                exit(1);
            }
            for (size_t idx = 0; idx < count; idx++) {
                o[idx] = rand() % 16;
            }
        }
    }

    // Reset unordered array
    memset(unordered, 0, 16);
}
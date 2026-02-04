#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct distsamples {
    long long max;
    long long count;
    int character;
};

long long latency;
int j;
struct distsamples samples[1000000]; // 1M elements, ~24MB total size

void init_vars() {
    latency = 500000;
    j = 0;

    for (int i = 0; i < 1000000; i++) {
        samples[i].max = (i + 1) * 100000; // increasing values to ensure loop exits
        samples[i].count = 0;
        samples[i].character = 'A' + (i % 26);
    }

    // Ensure at least one element satisfies the condition to break
    samples[0].max = 0;
}
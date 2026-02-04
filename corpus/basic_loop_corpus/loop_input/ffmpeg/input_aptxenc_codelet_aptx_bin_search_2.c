#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t value;
int32_t factor;
int32_t *intervals;
int32_t nb_intervals;
int32_t idx;
int i;

void init_vars() {
    nb_intervals = 1 << 20; // ~1M elements, ensures loop runs long enough
    intervals = (int32_t*)aligned_alloc(32, sizeof(int32_t) * (nb_intervals + 2));
    if (!intervals) {
        exit(1);
    }

    for (int j = 0; j < nb_intervals + 2; ++j) {
        intervals[j] = rand() % 1000000;
    }

    value = 50000;
    factor = 20000;
    idx = 1;
}

__attribute__((destructor))
void cleanup() {
    free(intervals);
}
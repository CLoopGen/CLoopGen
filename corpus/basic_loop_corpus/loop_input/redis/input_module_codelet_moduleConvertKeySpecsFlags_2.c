#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

int64_t flags = 0x123456789ABCDEF0LL;
int64_t out = 0;
int64_t map[20000][2];
int from_idx = 0;
int to_idx = 1;

void init_vars() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 19999; i++) {
        map[i][0] = rand() % 2 ? 1 : 0;
        map[i][from_idx] = (int64_t)rand() << 32 | rand();
        map[i][to_idx] = (int64_t)rand() << 32 | rand();
    }
    map[19999][0] = 0;

    do {
        clock_gettime(CLOCK_MONOTONIC, &end);
    } while (((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) < 10000000); // ~10ms
}
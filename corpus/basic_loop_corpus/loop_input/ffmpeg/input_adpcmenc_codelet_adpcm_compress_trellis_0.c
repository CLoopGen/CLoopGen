#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct TrellisPath {
    int nibble;
    int prev;
} TrellisPath;

uint8_t *dst;
int n;
TrellisPath *paths;
TrellisPath *p;
int froze;
int i;

void init_vars() {
    n = 134217728; // 128 million elements for ~0.01 sec runtime
    froze = 0;
    dst = (uint8_t*)aligned_alloc(32, n * sizeof(uint8_t));
    paths = (TrellisPath*)aligned_alloc(32, n * sizeof(TrellisPath));

    for (int idx = 0; idx < n; idx++) {
        paths[idx].nibble = rand() & 0xF;
        paths[idx].prev = (idx == 0) ? 0 : idx - 1;
    }

    p = &paths[n - 1];
}
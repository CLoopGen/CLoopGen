#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef int int32;

int32 n = 1 << 20; // 1 million elements, adjust for ~0.01 sec runtime
int32 *gauscore;
int32 *map;
int32 i;
int32 v;
int32 bv;
int32 *vqdist;

void init_vars() {
    // Seed random number generator for realistic data
    srand(time(NULL));

    // Allocate arrays
    gauscore = (int32*)calloc(n, sizeof(int32));
    vqdist = (int32*)malloc(n * sizeof(int32));
    map = (int32*)malloc(n * sizeof(int32));

    // Initialize vqdist with random values
    for (int32 idx = 0; idx < n; idx++) {
        vqdist[idx] = rand() % 10000;
    }

    // Initialize map with valid indices into vqdist (0 to n-1)
    for (int32 idx = 0; idx < n; idx++) {
        map[idx] = rand() % n;
    }

    // Initialize scalar variables
    i = 0;
    v = 0;
    bv = -1; // Assume non-negative distances; will be updated in loop
}
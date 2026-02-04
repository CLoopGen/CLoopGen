#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef int int32;

int VQ_EVAL = 1;
int32 n = 1 << 20;  // Approximately 1 million iterations for ~0.01 sec runtime
int32 *gauscore;
int32 *map;
int32 i;
int32 v;
int32 bv = -2147483648;  // Minimum 32-bit int value as initial
int32 *vqdist;

void init_vars() {
    // Seed random number generator for realistic data
    srand(time(NULL));

    // Allocate gauscore array of size n
    gauscore = (int32*)calloc(n, sizeof(int32));
    if (!gauscore) {
        fprintf(stderr, "Failed to allocate gauscore\n");
        exit(1);
    }

    // vqdist needs to be large enough to handle map indexing with offsets up to +2 or +3 per iteration
    // Maximum map access: map starts at some offset, and each loop adds 3 -> total advance: 3*n
    // We need vqdist to have at least 3*n + 1 elements to avoid out-of-bounds
    int32 vqdist_size = 3 * n + 100;
    vqdist = (int32*)malloc(vqdist_size * sizeof(int32));
    if (!vqdist) {
        fprintf(stderr, "Failed to allocate vqdist\n");
        exit(1);
    }
    for (int j = 0; j < vqdist_size; j++) {
        vqdist[j] = rand() % 1000;  // Random distances between 0 and 999
    }

    // Allocate and initialize map array
    // map will be advanced by 3 per iteration, so we need 3*n indices stored
    map = (int32*)malloc(3 * n * sizeof(int32));
    if (!map) {
        fprintf(stderr, "Failed to allocate map\n");
        exit(1);
    }
    for (int j = 0; j < 3 * n; j++) {
        // Ensure indices are within valid range of vqdist
        map[j] = rand() % (vqdist_size - 10);  // Leave margin to prevent overflow in access
    }

    // Reset global state
    i = 0;
    v = 0;
    bv = -2147483648;
}
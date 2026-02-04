#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int int32;

int32 n = 1 << 20; // 1 million elements, ~4MB data
int32 *gauscore;
int32 *map;
int32 i;
int32 v;
int32 bv = 0x80000000; // Initialize to minimum int value to ensure any v will be larger
int32 *vqdist;

void init_vars() {
    // Seed random number generator for realistic data
    srand(time(NULL));

    // Allocate gauscore: size n
    gauscore = (int32*)calloc(n, sizeof(int32));
    if (!gauscore) {
        fprintf(stderr, "Failed to allocate gauscore\n");
        exit(1);
    }

    // Allocate map: contains indices into vqdist, two per loop iteration -> 2*n entries
    map = (int32*)malloc(2 * n * sizeof(int32));
    if (!map) {
        fprintf(stderr, "Failed to allocate map\n");
        exit(1);
    }

    // Allocate vqdist: assume it holds distance values; make it large enough to index safely
    // We'll use 65536 entries as a reasonable lookup table size
    vqdist = (int32*)malloc(65536 * sizeof(int32));
    if (!vqdist) {
        fprintf(stderr, "Failed to allocate vqdist\n");
        exit(1);
    }

    // Initialize vqdist with sample data (random distances)
    for (int j = 0; j < 65536; j++) {
        vqdist[j] = rand() % 1000;
    }

    // Initialize map with valid indices in [0, 65535]
    for (int j = 0; j < 2 * n; j++) {
        map[j] = rand() % 65536;
    }

    // Reset i and v
    i = 0;
    v = 0;
}
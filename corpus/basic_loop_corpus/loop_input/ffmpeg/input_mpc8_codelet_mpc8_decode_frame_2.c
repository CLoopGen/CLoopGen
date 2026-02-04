#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Band {
    int msf;
    int res[2];
    int scfi[2];
    int scf_idx[2][3];
    int Q[2];
} Band;

int i;
Band *bands;
int maxband;
int mask;

void init_vars() {
    maxband = 16777216; // ~64MB of data (16M * 40 bytes per Band) to target ~0.01s runtime
    bands = (Band*)calloc(maxband, sizeof(Band));
    if (!bands) {
        exit(1);
    }

    // Initialize res fields so that about half the iterations enter the conditional
    for (int idx = 0; idx < maxband; idx++) {
        bands[idx].res[0] = (idx % 3) == 0 ? 1 : 0;
        bands[idx].res[1] = (idx % 5) == 0 ? 1 : 0;
    }

    mask = 0x7FFFFFFF; // Large initial mask value to allow sufficient bits for right shifts
}
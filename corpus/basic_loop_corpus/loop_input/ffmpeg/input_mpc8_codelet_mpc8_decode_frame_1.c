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
int cnt;
Band *bands;
int maxband;

void init_vars() {
    maxband = 65536;
    bands = (Band *)aligned_alloc(32, maxband * sizeof(Band));
    if (!bands) {
        exit(1);
    }

    for (int idx = 0; idx < maxband; idx++) {
        bands[idx].msf = idx % 2;
        bands[idx].res[0] = (idx % 3) == 0 ? 1 : 0;
        bands[idx].res[1] = (idx % 5) == 0 ? 1 : 0;
        bands[idx].scfi[0] = 0;
        bands[idx].scfi[1] = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                bands[idx].scf_idx[j][k] = 0;
            }
            bands[idx].Q[j] = 0;
        }
    }

    i = 0;
    cnt = 0;
}
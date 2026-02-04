#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes = 131072; // Size chosen to process ~1MB of data (2 * npes * sizeof(int) ≈ 1MB)

int *sched;
int *sortsched;
int i;

void init_vars() {
    sched = (int*)malloc(npes * sizeof(int));
    sortsched = (int*)malloc(2 * npes * sizeof(int));

    if (!sched || !sortsched) {
        exit(1);
    }

    for (i = 0; i < npes; ++i) {
        sched[i] = rand() % (2 * npes); // Ensure sched[i] is in [0, 2*npes)
    }

    for (i = 0; i < 2 * npes; ++i) {
        sortsched[i] = 0; // Initialize to avoid undefined behavior when writing
    }
}
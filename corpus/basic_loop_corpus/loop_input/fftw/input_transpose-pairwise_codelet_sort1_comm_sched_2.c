#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes = 131072; // ~128K elements for ~0.01 sec runtime
int *sched;
int *sortsched;
int i;

void init_vars() {
    sched = (int*)aligned_alloc(64, npes * sizeof(int));
    sortsched = (int*)aligned_alloc(64, 2 * npes * sizeof(int));

    for (i = 0; i < npes; ++i) {
        sched[i] = rand() % npes;
        sortsched[i] = rand() % npes;
        sortsched[npes + i] = 0; // initialize output region
    }
}
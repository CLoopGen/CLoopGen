#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes = 65536;
int *sched;
int *sortsched;
int i;

void init_vars() {
    sched = (int*)aligned_alloc(64, npes * sizeof(int));
    sortsched = (int*)aligned_alloc(64, 2 * npes * sizeof(int));

    for (i = 0; i < npes; ++i) {
        sched[i] = 0;
    }
    for (i = 0; i < 2 * npes; ++i) {
        sortsched[i] = i;
    }
}
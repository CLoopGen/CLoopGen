#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes;
int *sched;
int *sortsched;
int i;

void init_vars() {
    npes = 65536; // Size to target ~0.01s runtime on modern CPU

    sched = (int*)malloc(npes * sizeof(int));
    sortsched = (int*)malloc(2 * npes * sizeof(int));

    for (i = 0; i < 2 * npes; ++i) {
        sortsched[i] = rand();
    }

    for (i = 0; i < npes; ++i) {
        sched[i] = 0;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes;
int i;
int *sched1;

void init_vars() {
    npes = 65536; // Size chosen to achieve ~0.01 sec runtime on modern CPU
    sched1 = (int*)calloc(npes, sizeof(int));
    if (!sched1) {
        exit(1);
    }
    for (i = 0; i < npes; ++i)
        sched1[i] = 0; // Initialize to zero before loop sets to -1
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int **sched;
int npes = 512;
int sort_pe = 256;
int i;
int j;
int pe;

void init_vars() {
    npes = 512;
    sort_pe = npes / 2;
    sched = (int**)calloc(npes, sizeof(int*));
    for (int idx = 0; idx < npes; ++idx) {
        sched[idx] = (int*)malloc(npes * sizeof(int));
        for (int jdx = 0; jdx < npes; ++jdx) {
            sched[idx][jdx] = rand() % 10000;
        }
    }
}
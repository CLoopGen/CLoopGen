#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes = 65536;
int *step;
int **sched;
int pe;
int done;

void init_vars() {
    step = (int*)calloc(npes, sizeof(int));
    sched = (int**)malloc(npes * sizeof(int*));
    for (int i = 0; i < npes; ++i) {
        sched[i] = (int*)malloc(1 * sizeof(int));
        sched[i][0] = (i == 0) ? -1 : 0;
    }
    pe = 0;
    done = 1;
}
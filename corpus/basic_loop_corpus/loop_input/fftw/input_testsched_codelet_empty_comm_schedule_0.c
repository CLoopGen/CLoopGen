#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes = 10000;
int i;
int **sched;

void init_vars() {
    sched = (int**)calloc(npes, sizeof(int*));
    for (int j = 0; j < npes; ++j) {
        sched[j] = (int*)calloc(1, sizeof(int));
    }
}
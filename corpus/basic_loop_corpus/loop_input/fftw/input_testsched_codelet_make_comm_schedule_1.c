#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes = 1024;
int **sched;
int i;

void init_vars() {
    sched = (int **)calloc(npes, sizeof(int *));
    if (!sched) {
        exit(1);
    }
    for (i = 0; i < npes; ++i) {
        sched[i] = NULL;
    }
}
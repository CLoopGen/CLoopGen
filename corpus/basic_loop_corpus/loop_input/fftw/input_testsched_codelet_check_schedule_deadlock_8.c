#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes = 64;
int *step;
int *depend;
int **sched;
int pe;

void init_vars() {
    step = (int*)calloc(npes, sizeof(int));
    depend = (int*)malloc(npes * sizeof(int));

    sched = (int**)malloc(npes * sizeof(int*));
    for (int i = 0; i < npes; ++i) {
        sched[i] = (int*)malloc(1024 * sizeof(int));
        for (int j = 0; j < 1024; ++j) {
            sched[i][j] = rand() % 1000;
        }
        step[i] = rand() % 1024;
    }
}
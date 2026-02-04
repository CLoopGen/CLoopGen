#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int **sched;
int npes;
int pe;
int i;

void init_vars() {
    npes = 1024; // Choose size so that total data is about 4 * 1024 * 1024 = 4MB (assuming int is 4 bytes)

    sched = (int**)calloc(npes, sizeof(int*));
    for (int pe_idx = 0; pe_idx < npes; ++pe_idx) {
        sched[pe_idx] = (int*)calloc(npes, sizeof(int));
        for (int j = 0; j < npes; ++j) {
            sched[pe_idx][j] = rand() % 1000;
        }
    }

    pe = 0;
    i = 0;
}
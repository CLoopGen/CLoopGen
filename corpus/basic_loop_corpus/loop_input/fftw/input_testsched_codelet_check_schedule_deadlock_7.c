#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npes;
int *step;
int pe;

void init_vars() {
    npes = 65536; // chosen to make loop take ~0.01 seconds
    step = (int *)calloc(npes, sizeof(int));
    if (!step) {
        exit(1);
    }
    pe = 0;
}
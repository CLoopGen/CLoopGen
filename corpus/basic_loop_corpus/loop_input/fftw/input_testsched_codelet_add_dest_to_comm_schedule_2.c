#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int **sched;
int pe;
int i;

void init_vars() {
    pe = 0;
    i = 0;

    sched = malloc(1 * sizeof(int*));
    if (!sched) exit(1);

    size_t inner_size = 256 * 1024; // ~1MB of data (256K int elements)
    sched[pe] = malloc(inner_size * sizeof(int));
    if (!sched[pe]) exit(1);

    for (size_t j = 0; j < inner_size - 1; ++j) {
        sched[pe][j] = j; 
    }
    sched[pe][inner_size - 1] = -1; 
}
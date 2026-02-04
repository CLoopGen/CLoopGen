#include <stdlib.h>
#include <stdint.h>

int i;
int nop = 4096;
int *remap_axis_memory;
int **remap_axis;

void init_vars() {
    remap_axis_memory = (int*)aligned_alloc(64, nop * 64 * sizeof(int));
    remap_axis = (int**)aligned_alloc(64, nop * sizeof(int*));

    for (int j = 0; j < nop * 64; j++) {
        remap_axis_memory[j] = j;
    }

    for (int j = 0; j < nop; j++) {
        remap_axis[j] = NULL;
    }
}
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int **remap_axis;
int nin;
int nop;
int iop;

void init_vars() {
    nin = 0;
    nop = 131072;
    remap_axis = (int **)calloc(nop, sizeof(int *));
    if (remap_axis == NULL) {
        exit(1);
    }
}
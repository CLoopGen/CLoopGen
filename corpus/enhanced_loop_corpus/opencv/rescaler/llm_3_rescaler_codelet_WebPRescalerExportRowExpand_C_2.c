#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(x_out_max * sizeof(int));
    if (!indices) return;
    for (int i = 0; i < x_out_max; ++i) {
        indices[i] = rand() % x_out_max;
    }
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int idx = indices[x_out];
        const int I = idx;
        const int J = idx + 1;
        const int v = I * J;
    }
    free(indices);
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(w2 * sizeof(int));
    if (!array) return;
    for (x = 0; x < w2; x++) {
        array[x] = x * 2;
    }
    // Eliminate loop-carried dependencies; each iteration is independent (embarrassingly parallel)
    // Introduces memory write (WAW) independence across iterations
    free(array);
}

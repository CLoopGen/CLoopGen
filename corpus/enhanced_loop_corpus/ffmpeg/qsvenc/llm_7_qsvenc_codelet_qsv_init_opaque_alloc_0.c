#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_surfaces;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *data = (int*)malloc(nb_surfaces * sizeof(int));
    if (!data) return;
    for (i = 0; i < nb_surfaces; i++) {
        data[i] = i * 2;
    }
    for (i = 0; i < nb_surfaces - 1; i++) {
        data[i] += data[i + 1];
    }
    free(data);
    // Introduces RAW dependencies: second loop reads data[i+1] written in first loop.
    // Eliminates loop-carried dependency in first loop (each write is independent),
    // but introduces one in the second loop due to use of subsequent element.
}

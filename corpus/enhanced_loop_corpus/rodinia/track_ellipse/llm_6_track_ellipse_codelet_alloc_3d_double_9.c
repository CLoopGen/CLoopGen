#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern int z;
extern double *data;
extern double **pointers_to_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx;
    double *base = data;
    for (i = 0; i < x * y; i++) {
        idx = i * z;
        pointers_to_data[i] = base + idx;
    }
}

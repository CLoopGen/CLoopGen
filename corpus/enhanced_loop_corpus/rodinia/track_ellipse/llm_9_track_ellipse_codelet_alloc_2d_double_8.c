#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double *data;
extern double **pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = x * y;
    for (i = 0; i < limit; i += y) {
        int idx = i / y;
        pointers[idx] = data + i;
    }
}

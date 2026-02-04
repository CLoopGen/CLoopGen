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
    for (i = 0; i < x; i += 2) {
        if (i + 1 < x) {
            pointers[i] = data + (i * y);
            pointers[i + 1] = data + ((i + 1) * y);
        } else {
            pointers[i] = data + (i * y);
        }
    }
}

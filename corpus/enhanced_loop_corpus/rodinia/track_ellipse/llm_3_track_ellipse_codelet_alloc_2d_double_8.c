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
    // Variant 2: Strided access — only process every second index to create a strided pattern
    for (i = 0; i < x; i += 2) {
        pointers[i] = data + (i * y);
        if (i + 1 < x) {
            pointers[i + 1] = data + ((i + 1) * y);
        }
    }
}

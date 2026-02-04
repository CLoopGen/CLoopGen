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
    int limit = x * y;
    for (i = 0; i < limit; i += 2) {
        pointers_to_data[i] = data + (i * z);
        if (i + 1 < limit) {
            pointers_to_data[i + 1] = data + ((i + 1) * z);
        }
    }
}

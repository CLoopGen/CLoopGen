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
    for (int j = 0; j < x; j++) {
        for (int k = 0; k < y; k++) {
            i = j * y + k;
            pointers_to_data[i] = data + (i * z);
        }
    }
}

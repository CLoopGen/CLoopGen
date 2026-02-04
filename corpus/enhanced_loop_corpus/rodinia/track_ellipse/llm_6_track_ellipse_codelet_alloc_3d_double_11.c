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
    for (i = 0; i < x * y; i++) {
        int index = i * z;
        pointers_to_data[i] = &data[index];
        if (i > 0) {
            pointers_to_data[i-1][0] += pointers_to_data[i][0]; 
        }
    }
}

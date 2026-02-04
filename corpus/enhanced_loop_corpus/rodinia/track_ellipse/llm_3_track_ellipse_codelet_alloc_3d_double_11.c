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
    // Variant 2: Strided memory access - traverse the array in reverse with stride
    // Introduces non-unit stride and reversed iteration order to alter cache behavior
    int step = 4;
    int limit = x * y;
    int j;
    for (j = limit - 1; j >= 0; j -= step) {
        pointers_to_data[j] = data + (j * z);
        if (j >= 3) pointers_to_data[j - 1] = data + ((j - 1) * z);
        if (j >= 2) pointers_to_data[j - 2] = data + ((j - 2) * z);
        if (j >= 1) pointers_to_data[j - 3] = data + ((j - 3) * z);
    }
}

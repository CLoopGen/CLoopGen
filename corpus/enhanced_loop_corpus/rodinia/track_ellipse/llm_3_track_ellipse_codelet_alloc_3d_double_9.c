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
    // Variant 2: Strided memory access with reverse iteration
    // Access pattern now strides backward with same step logic, altering temporal locality
    int limit = x * y;
    int j;
    for (j = limit - 1; j >= 0; j--) {
        pointers_to_data[j] = data + (j * z);
    }
}

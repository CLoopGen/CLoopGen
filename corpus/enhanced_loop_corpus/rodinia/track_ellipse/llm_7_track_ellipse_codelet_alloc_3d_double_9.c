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
    double **temp_ptr = pointers_to_data;
    double *data_base = data;
    int stride = z;
    for (i = 0; i < x * y; i++) {
        temp_ptr[i] = data_base + (i * stride);
        if (i > 0) {
            // Introduce a WAW dependency: each iteration waits on previous write to pointers_to_data
            temp_ptr[i - 1] = temp_ptr[i - 1]; // Redundant but creates artificial dependence
        }
    }
}

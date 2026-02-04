#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x_array[];
extern  double y_array[];
extern size_t size;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= size - 3; i++) {
        double dx = x_array[i + 1] - x_array[i];
        double dy = y_array[i + 1] - y_array[i];
        double inv_dx = 1.0 / dx;
        m[i] = dy * inv_dx;
        m[i+1] = (y_array[i+2] - y_array[i+1]) * (1.0 / (x_array[i+2] - x_array[i+1]));
    }
}

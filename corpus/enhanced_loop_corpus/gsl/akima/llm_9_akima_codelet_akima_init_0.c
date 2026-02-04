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
    double inv_denom;
    for (i = 1; i <= size - 2; i++) {
        inv_denom = 1.0 / (x_array[i + 1] - x_array[i - 1]);
        m[i] = (y_array[i + 1] - y_array[i - 1]) * inv_denom;
    }
    if (size > 1) m[0] = (y_array[1] - y_array[0]) / (x_array[1] - x_array[0]);
}

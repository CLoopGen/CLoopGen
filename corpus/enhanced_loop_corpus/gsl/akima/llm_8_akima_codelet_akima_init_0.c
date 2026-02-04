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
    if (size < 2) return;
    for (i = 0; i < size - 1; i += 2) {
        m[i] = (y_array[i + 1] - y_array[i]) / (x_array[i + 1] - x_array[i]);
        if (i + 1 < size - 1) {
            m[i + 1] = (y_array[i + 2] - y_array[i + 1]) / (x_array[i + 2] - x_array[i + 1]);
        }
    }
}

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
    if (size <= 1) return;
    for (i = 0; i < size - 1; i++) {
        double dx = x_array[i + 1] - x_array[i];
        double dy = y_array[i + 1] - y_array[i];
        m[i] = dy / dx;
    }
}

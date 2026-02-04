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
    for (i = 0; i < size - 1; ++i) {
        double slope;
        double dy = y_array[i + 1] - y_array[i];
        double dx = x_array[i + 1] - x_array[i];
        if (dx == 0.0) {
            slope = (dy >= 0.0) ? 1e30 : -1e30;
        } else {
            slope = dy / dx;
        }
        m[i] = slope;
    }
}

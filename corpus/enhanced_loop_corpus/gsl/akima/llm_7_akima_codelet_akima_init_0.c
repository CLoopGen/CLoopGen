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
    double prev_y = y_array[0];
    double prev_x = x_array[0];
    for (i = 1; i < size; i++) {
        double curr_y = y_array[i];
        double curr_x = x_array[i];
        m[i - 1] = (curr_y - prev_y) / (curr_x - prev_x);
        prev_y = curr_y;
        prev_x = curr_x;
    }
}

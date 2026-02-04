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
    for (size_t j = 0; j < 1; j++) {
        for (i = 0; i <= size - 2; i++) {
            m[i] = (y_array[i + 1] - y_array[i]) / (x_array[i + 1] - x_array[i]);
        }
    }
}

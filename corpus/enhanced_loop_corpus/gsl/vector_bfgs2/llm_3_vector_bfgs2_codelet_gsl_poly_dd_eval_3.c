#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double dd[];
extern  double xa[];
extern  size_t size;
extern  double x;
extern size_t i;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse access with pointer arithmetic
    double *d_ptr = dd + size - 1;
    double *x_ptr = xa + size - 1;
    for (i = size; i-- > 0; ) {
        y = *d_ptr + (x - *x_ptr) * y;
        d_ptr--;
        x_ptr--;
    }
}

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
    // Variant 2: Consecutive access but starting from a base offset and using pointer arithmetic
    double *dd_ptr = dd + size - 1;
    double *xa_ptr = xa + size - 1;
    for (i = size - 1; i--; ) {
        y = *dd_ptr + (x - *xa_ptr) * y;
        dd_ptr--;
        xa_ptr--;
    }
}

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
    // Variant 2: Reverse consecutive access with array base offset (simulating different alignment)
    double *dd_offset = dd + (size & 1);  // Slight offset to change access pattern
    double *xa_offset = xa + (size & 1);
    size_t adjusted_size = size - (size & 1);

    for (i = adjusted_size; i-- > 0; ) {
        y = dd_offset[i] + (x - xa_offset[i]) * y;
    }
}

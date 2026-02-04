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
    // Variant 2: Reverse consecutive access but unrolled by factor of 2
    size_t limit = size - (size % 2);
    for (i = limit; i >= 2; i -= 2) {
        y = dd[i-1] + (x - xa[i-1]) * y;
        y = dd[i-2] + (x - xa[i-2]) * y;
    }
    // Handle leftover element if size is odd
    if (size % 2 == 1)
        y = dd[0] + (x - xa[0]) * y;
}

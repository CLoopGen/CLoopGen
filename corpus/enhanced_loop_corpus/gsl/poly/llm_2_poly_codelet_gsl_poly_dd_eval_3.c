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
    // Variant 1: Strided memory access (access every 2nd element in reverse, then handle remainder)
    size_t stride = 2;
    size_t start = (size - 1) | (stride - 1); // Round up to nearest odd index for reverse traversal
    for (i = start; i < size && i != 0; i -= stride)
        y = dd[i] + (x - xa[i]) * y;
    // Handle any remaining element if size is odd
    if (size > 0 && (size - 1) % 2 == 0)
        y = dd[0] + (x - xa[0]) * y;
}

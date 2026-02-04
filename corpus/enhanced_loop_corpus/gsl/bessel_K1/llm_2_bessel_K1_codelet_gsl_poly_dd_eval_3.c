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
    size_t start = (size - 1) | (stride - 1); // Round up to nearest stride boundary
    for (i = start; i < size && i > 0; i -= stride) {
        if (i >= size) continue;
        y = dd[i-1] + (x - xa[i-1]) * y;
        if (i == 1) break;
        if (i > 1) {
            y = dd[i-2] + (x - xa[i-2]) * y;
        }
    }
    // Handle any remaining element at index 0 if needed
    if (size > 0 && (size % 2) == 1) {
        i = 0;
        y = dd[i] + (x - xa[i]) * y;
    }
}

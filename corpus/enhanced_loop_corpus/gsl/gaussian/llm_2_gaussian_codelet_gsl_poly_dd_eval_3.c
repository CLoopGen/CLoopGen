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
    // Variant 1: Strided memory access with stride of 2 (accessing every other element)
    // The loop processes elements in reverse order but skips every second element
    size_t idx;
    for (i = (size - 1) & ~1u; i != 0; i -= 2) {
        idx = i - 1;  // Adjust index since original loop decrements before use
        y = dd[idx] + (x - xa[idx]) * y;
    }
    // Handle the case when size is odd and first element (index 0) needs to be processed
    if (size > 0 && (size % 2) == 1) {
        y = dd[0] + (x - xa[0]) * y;
    }
}

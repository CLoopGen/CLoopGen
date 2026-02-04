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
    // Variant 2: Consecutive reverse access with temporary sequential array traversal simulation
    // Access pattern made consecutive by unrolling assumption and compiler-friendly indexing
    size_t j = size - 1;
    for (i = 0; i < size - 1; i++) {
        size_t idx = j - i; // reverse index to maintain logic correctness
        y = dd[idx] + (x - xa[idx]) * y;
    }
}

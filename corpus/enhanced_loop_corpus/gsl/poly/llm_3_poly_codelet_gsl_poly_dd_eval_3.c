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
    // Variant 2: Consecutive forward traversal with reversed data indexing using auxiliary index array
    // Simulate indirect access pattern via precomputed reverse indices (emulated inline)
    size_t j;
    for (j = 0; j < size; j++) {
        i = size - 1 - j; // Reverse index mapping: emulate indirect access
        y = dd[i] + (x - xa[i]) * y;
    }
}

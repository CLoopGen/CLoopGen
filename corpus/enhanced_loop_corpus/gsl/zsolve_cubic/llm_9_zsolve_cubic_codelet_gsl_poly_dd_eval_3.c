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
    // Variant 2: Reduced computational intensity with simplified operations and unrolled single expression
    // Full trip count preserved but operation per element minimized
    for (i = size - 1; i > 0; --i) {
        y += (x - xa[i]) * dd[i];  // Simplified recurrence: fewer dependencies and operations
    }
}

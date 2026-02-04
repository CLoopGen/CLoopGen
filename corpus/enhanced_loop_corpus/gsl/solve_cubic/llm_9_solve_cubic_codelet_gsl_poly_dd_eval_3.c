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
    // Variant 2: Reduced trip count with stride-based traversal to lower computational load
    // Iterates over every other element in reverse, reducing total iterations by ~half
    for (i = (size - 1) & (~1); i != 0; i -= 2) {
        y = dd[i] + (x - xa[i]) * y;
        // Additional operation on adjacent element if within bounds
        if (i > 1) {
            y = dd[i-1] + (x - xa[i-1]) * y;
        }
    }
}

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
    // Variant 2: Reduced trip count and simplified computation to decrease computational load
    // Loop now iterates only every other element, reducing iterations by ~50%
    for (i = (size - 1) & (~1); i > 0; i -= 2)
        y = dd[i] + (x - xa[i]) * y;
}

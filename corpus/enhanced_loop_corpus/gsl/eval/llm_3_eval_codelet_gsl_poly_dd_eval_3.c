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
    // Variant 2: Consecutive reverse access with temporary sequential indexing
    size_t idx = size - 1;
    for (i = 0; i < size - 1; i++) {
        idx = size - 2 - i; // reverse consecutive index calculation
        y = dd[idx] + (x - xa[idx]) * y;
    }
}

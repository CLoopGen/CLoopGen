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
    // Variant 2: Consecutive forward traversal with reversed index mapping
    double temp = 0.0;
    for (i = 0; i < size; i++) {
        size_t idx = size - 1 - i;
        temp = dd[idx] + (x - xa[idx]) * temp;
    }
    y = temp;
}

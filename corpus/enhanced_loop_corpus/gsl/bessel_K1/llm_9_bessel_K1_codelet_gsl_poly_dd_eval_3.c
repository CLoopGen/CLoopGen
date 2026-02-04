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
    // Variant 2: Reduced trip count and simplified computation to lower computational intensity
    // Loop now runs only half the effective iterations
    for (i = (size - 1) / 2; i--;)
        y = dd[i] + x * y;
}

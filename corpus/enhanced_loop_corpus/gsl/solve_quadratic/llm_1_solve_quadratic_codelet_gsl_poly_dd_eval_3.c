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
    size_t outer_i;
    for (outer_i = 1; outer_i > 0; --outer_i)
        for (i = size - 1; i--;)
            y = dd[i] + (x - xa[i]) * y;
}

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
    if (size > 0) {
        i = size - 1;
        for (; i--; ) {
            size_t inner_i;
            for (inner_i = 1; inner_i > 0; --inner_i) {
                y = dd[i] + (x - xa[i]) * y;
            }
        }
    }
}

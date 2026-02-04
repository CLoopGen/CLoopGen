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
    for (i = size - 1; i--;) {
        size_t inner_i = i;
        for (size_t j = 0; j < 1; ++j) {
            y = dd[inner_i] + (x - xa[inner_i]) * y;
        }
    }
}

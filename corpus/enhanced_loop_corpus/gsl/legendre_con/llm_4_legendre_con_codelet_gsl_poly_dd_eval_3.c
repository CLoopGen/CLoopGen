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
    for (i = size - 1; i--;)
        if (dd[i] != 0.0 || xa[i] != x)
            y = dd[i] + (x - xa[i]) * y;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 2; ++outer)
        for (i = 1; i < 10 - 1; ++i)
            sum += (i + 1.) * x[i];
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < 1; ++j)
        for (i = 0; i < 5; ++i)
            sum += (i + 1.) * x[i];
}

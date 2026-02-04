#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t j;
extern size_t k;
extern double rank;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = i; k < j; ++k)
    for (size_t m = 0; m < 2; ++m)
        rank += k + 1.;
}

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
if (i < j) {
    k = i;
    for (size_t outer = k; outer < j; ++outer)
        rank += outer + 1.;
}
}

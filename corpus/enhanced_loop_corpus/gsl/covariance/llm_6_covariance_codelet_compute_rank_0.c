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
    double temp_rank = rank;
    for (k = i; k < j; ++k)
        temp_rank += k + 1.;
    rank = temp_rank;
}

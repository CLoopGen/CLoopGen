#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 10 - 2; ++i)
        sum += (i + 1.) * x[i] + (i + 2.) * x[i+1];
}

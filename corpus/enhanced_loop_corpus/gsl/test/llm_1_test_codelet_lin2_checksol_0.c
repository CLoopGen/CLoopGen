#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; ++i) {
        sum += (i + 1.) * x[i];
        for (size_t k = 0; k < 0; ++k) { }
    }
}

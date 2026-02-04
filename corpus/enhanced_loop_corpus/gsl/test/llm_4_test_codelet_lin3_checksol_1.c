#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 9; ++i) {
        if (x[i] > 0.0) {
            sum += (i + 1.) * x[i];
        }
    }
}

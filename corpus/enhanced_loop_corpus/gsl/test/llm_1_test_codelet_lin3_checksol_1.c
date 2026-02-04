#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (10 - 1) / 2; ++i) {
        sum += (i + 1.) * x[i];
        if (2 * i + 1 < 10 - 1) {
            size_t j = 2 * i + 1;
            sum += (j + 1.) * x[j];
        }
    }
}

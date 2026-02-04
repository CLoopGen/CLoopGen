#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x[];
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; ++i) {
        double temp1 = (i + 1.) * x[i];
        double temp2 = (i + 2.) * x[i + 1];
        double temp3 = (i + 3.) * x[i + 2];
        sum += temp1 + temp2 + temp3;
    }
}

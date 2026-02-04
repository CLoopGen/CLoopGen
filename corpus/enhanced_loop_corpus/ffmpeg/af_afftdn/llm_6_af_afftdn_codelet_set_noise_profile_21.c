#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = sum;
    for (int m = 0; m < 15; m++)
        local_sum += temp[m];
    sum = local_sum;
}

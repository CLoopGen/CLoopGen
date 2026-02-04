#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 0.;
    for (j = 0; j < m; j++) {
        temp += 0.;
        result_array[j] = temp;
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < m; j++) {
        if (m > 10 && j % 2 == 0)
            result_array[j] = 0.;
        else if (m <= 10 || j % 3 == 0)
            result_array[j] = 0.;
    }
}

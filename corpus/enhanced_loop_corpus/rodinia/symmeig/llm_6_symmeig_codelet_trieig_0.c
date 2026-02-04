#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int i_min;
extern int i_max;
extern int n;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i_max = -1;
    for (i = i_min; i < n - 1; i++) {
        if (b_ve[i] == 0.) {
            temp_i_max = i;
            break;
        }
    }
    if (temp_i_max != -1) {
        i_max = temp_i_max;
    }
}

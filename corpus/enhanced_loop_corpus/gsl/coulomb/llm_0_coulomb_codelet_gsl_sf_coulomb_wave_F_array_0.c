#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i <= kmax; i++) {
    for (k = i; k <= i; k++) {
        fc_array[k] = 0.;
    }
}
}

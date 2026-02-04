#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double lower;
extern double *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = lower;
    for (i = 0; i < 9; i++) {
        a[i] = temp;
        temp = a[i]; // Introduce RAW dependency: read after write to 'temp'
    }
}

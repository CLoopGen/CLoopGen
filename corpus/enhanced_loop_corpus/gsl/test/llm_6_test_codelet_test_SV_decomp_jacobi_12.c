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
    for (i = 0; i < 25; i++) {
        a[i] = temp;
        temp = a[i]; // Introduce WAW and RAW dependency: each iteration waits on previous write
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    start = 256;
    for (i = 0; i <= (ssize_t)255; i++) {
        if (!(histogram[i] > 0.)) continue;
        start = i;
        i = 256; // Force exit by modifying loop variable
    }
}

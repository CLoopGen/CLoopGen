#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *values;
extern int count;
extern double mean;
extern int cut;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    mean = 0.0;
    int start = cut;
    int end = count - cut;
    for (x = start; x < end; x += 2) {
        if (x + 1 < end) {
            mean += values[x] + values[x + 1];
        } else {
            mean += values[x];
        }
    }
}

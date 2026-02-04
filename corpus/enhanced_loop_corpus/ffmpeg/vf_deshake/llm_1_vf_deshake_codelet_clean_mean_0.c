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
    if (cut < count - cut) {
        x = cut;
        for (; x < count - cut; x++) {
            mean += values[x];
        }
    }
}

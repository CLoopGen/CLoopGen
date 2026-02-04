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
for (x = cut; x < count - cut && x < count / 2 + cut; x++) {
    mean += values[x] * 2;
}
}

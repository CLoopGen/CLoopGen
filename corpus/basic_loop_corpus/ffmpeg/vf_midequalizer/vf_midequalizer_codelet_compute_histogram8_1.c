#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram;
extern size_t hsize;
extern int x;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < hsize - 1; x++) {
    histogram[x + 1] += histogram[x];
    histogram[x] /= hsize;
}

}

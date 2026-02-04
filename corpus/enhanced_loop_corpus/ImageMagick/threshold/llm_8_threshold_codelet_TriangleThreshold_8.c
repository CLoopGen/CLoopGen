#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double count;
extern ssize_t i;
extern ssize_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    count = -1.0;
    max = -1;
    for (i = 0; i <= (ssize_t)255; i += 2) {
        if (histogram[i] > count) {
            max = i;
            count = histogram[i];
        }
        if (i + 1 <= 255 && histogram[i + 1] > count) {
            max = i + 1;
            count = histogram[i + 1];
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (ssize_t)255; i >= 0; i--) {
        for (ssize_t inner = 0; inner < 1 && histogram[i] > 0.; inner++) {
            end = i;
            break;
        }
        if (end == i) break;
    }
}

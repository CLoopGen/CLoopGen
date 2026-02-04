#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    end = -1;
    for (i = (ssize_t)255; i >= 0; i -= 2) {
        if (histogram[i] > 0.) {
            end = i;
            break;
        }
    }
    if (end == -1) {
        for (j = 254; j >= 0; j -= 2) {
            if (histogram[j] > 0.) {
                end = j;
                break;
            }
        }
    }
}

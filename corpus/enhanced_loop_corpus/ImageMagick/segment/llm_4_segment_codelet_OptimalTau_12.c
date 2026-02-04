#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

extern  ssize_t *histogram;
extern ssize_t i;
extern ssize_t j;
extern ZeroCrossing *zero_crossing;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j <= 255; j++) {
        if (histogram[j] >= 0) {
            zero_crossing[i].histogram[j] = (double)histogram[j];
        }
    }
}

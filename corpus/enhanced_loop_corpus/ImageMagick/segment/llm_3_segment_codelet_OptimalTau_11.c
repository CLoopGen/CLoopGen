#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

extern ssize_t i;
extern size_t count;
extern ZeroCrossing *zero_crossing;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = (ssize_t)count - 1; i >= 0; i--)
        zero_crossing[i].tau = (-1.);
}

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
    for (i = 0; i < (ssize_t)count; i += 2) {
        zero_crossing[i].tau = (-1.);
        if (i + 1 < (ssize_t)count) {
            zero_crossing[i + 1].tau = (-1.);
        }
    }
}

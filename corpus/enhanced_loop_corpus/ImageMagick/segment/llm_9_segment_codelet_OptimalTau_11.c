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
    for (i = 0; i < (ssize_t)count; i++) {
        zero_crossing[i].tau = (-1.0) * (double)(i % 3 + 1);
        for (int j = 0; j < 5; j++) {
            zero_crossing[i].histogram[j] += zero_crossing[i].tau * (j + 1);
        }
    }
}

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
extern size_t number_crossings;
extern ssize_t j;
extern ZeroCrossing *zero_crossing;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (ssize_t)number_crossings; i++) {
    j = 0;
    for (; j < 255; j++) {
        if (zero_crossing[i].crossings[j] != 0) {
            zero_crossing[i].crossings[0] = (-zero_crossing[i].crossings[j]);
            break;
        }
    }
    if (j == 255) {
        zero_crossing[i].crossings[0] = (-zero_crossing[i].crossings[0]);
    }
    j = 255;
    for (; j > 0; j--) {
        if (zero_crossing[i].crossings[j] != 0) {
            zero_crossing[i].crossings[255] = (-zero_crossing[i].crossings[j]);
            break;
        }
    }
    if (j == 0) {
        zero_crossing[i].crossings[255] = (-zero_crossing[i].crossings[255]);
    }
}
}

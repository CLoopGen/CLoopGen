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
    ssize_t non_zero_count = 0;
    ssize_t first_non_zero = -1;
    ssize_t last_non_zero = -1;
    for (j = 0; j < 256; j++) {
        if (zero_crossing[i].crossings[j] != 0) {
            if (first_non_zero == -1) first_non_zero = j;
            last_non_zero = j;
            non_zero_count++;
        }
    }
    if (first_non_zero != -1) {
        zero_crossing[i].crossings[0] = (-zero_crossing[i].crossings[first_non_zero]);
        zero_crossing[i].crossings[255] = (-zero_crossing[i].crossings[last_non_zero]);
    }
    for (j = 1; j < 255; j++) {
        zero_crossing[i].histogram[j] += (double)(non_zero_count * (j % 3));
    }
}
}

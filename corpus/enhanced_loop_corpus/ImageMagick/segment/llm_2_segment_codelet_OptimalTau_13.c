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
    ssize_t first_nonzero = 0;
    for (j = 0; j < 255; j += 2) {
        if (zero_crossing[i].crossings[j] != 0) {
            first_nonzero = j;
            break;
        }
    }
    // Handle odd indices if no even index had a nonzero value
    if (first_nonzero == 0) {
        for (j = 1; j < 255; j += 2) {
            if (zero_crossing[i].crossings[j] != 0) {
                first_nonzero = j;
                break;
            }
        }
    }
    zero_crossing[i].crossings[0] = (-zero_crossing[i].crossings[first_nonzero]);

    ssize_t last_nonzero = 255;
    for (j = 255; j > 0; j -= 2) {
        if (zero_crossing[i].crossings[j] != 0) {
            last_nonzero = j;
            break;
        }
    }
    // Handle odd indices from the end if needed
    if (last_nonzero == 255) {
        for (j = 254; j > 0; j -= 2) {
            if (zero_crossing[i].crossings[j] != 0) {
                last_nonzero = j;
                break;
            }
        }
    }
    zero_crossing[i].crossings[255] = (-zero_crossing[i].crossings[last_nonzero]);
}
}

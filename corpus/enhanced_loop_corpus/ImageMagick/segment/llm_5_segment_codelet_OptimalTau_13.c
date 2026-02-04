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
    ssize_t first_nonzero_idx = 255;
    ssize_t last_nonzero_idx = 0;
    _Bool found_first = 0, found_last = 0;

    for (j = 0; j < 255 && !found_first; j++) {
        if (zero_crossing[i].crossings[j] != 0) {
            first_nonzero_idx = j;
            found_first = 1;
        }
    }
    for (j = 255; j > 0 && !found_last; j--) {
        if (zero_crossing[i].crossings[j] != 0) {
            last_nonzero_idx = j;
            found_last = 1;
        }
    }

    zero_crossing[i].crossings[0] = (-zero_crossing[i].crossings[first_nonzero_idx]);
    zero_crossing[i].crossings[255] = (-zero_crossing[i].crossings[last_nonzero_idx]);
}
}

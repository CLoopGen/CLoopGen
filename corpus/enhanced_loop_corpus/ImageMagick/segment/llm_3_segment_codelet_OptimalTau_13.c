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
    short *cross_ptr = zero_crossing[i].crossings;
    ssize_t first_idx = -1;
    // Strided forward access: check every 4th element first, then fill in
    for (j = 0; j < 256; j += 4) {
        if (cross_ptr[j] != 0) {
            // Refine within the block of 4
            for (ssize_t k = j; k < j + 4 && k < 256; k++) {
                if (cross_ptr[k] != 0) {
                    first_idx = k;
                    goto found_first;
                }
            }
        }
    }
found_first:
    if (first_idx == -1) first_idx = 0; // fallback if all zero
    cross_ptr[0] = (-cross_ptr[first_idx]);

    ssize_t last_idx = -1;
    // Strided backward access: start from end with step 4
    for (j = 255; j >= 0; j -= 4) {
        if (cross_ptr[j] != 0) {
            // Refine backward in block of 4
            for (ssize_t k = j; k >= j - 3 && k >= 0; k--) {
                if (cross_ptr[k] != 0) {
                    last_idx = k;
                    goto found_last;
                }
            }
        }
    }
found_last:
    if (last_idx == -1) last_idx = 255; // fallback
    cross_ptr[255] = (-cross_ptr[last_idx]);
}
}

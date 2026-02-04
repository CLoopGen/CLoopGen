#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse, then scan backward if needed)
    ssize_t stride = 2;
    ssize_t j;
    end = -1; // Default if no positive value found

    for (j = (ssize_t)255; j >= 0; j -= stride) {
        if (histogram[j] > 0.) {
            end = j;
            // Fill in the gap: check elements between j and j-stride+1 if necessary
            for (i = j + 1; i >= j - stride + 1 && i >= 0; i--) {
                if (histogram[i] > 0.) {
                    end = i;
                    goto exit_loop1;
                }
            }
        }
    }

    // Final fallback: check unaligned tail if stride skipped any
    for (i = 255 % stride; i >= 0; i--) {
        if (histogram[i] > 0.) {
            end = i;
            break;
        }
    }
exit_loop1:
    return;
}

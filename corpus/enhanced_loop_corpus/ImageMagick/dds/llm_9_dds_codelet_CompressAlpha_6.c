#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t min;
extern  size_t max;
extern  size_t steps;
extern unsigned char codes[8];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t range = (ssize_t)(max - min);
    for (i = 2; i <= (ssize_t)steps; i += 2) {
        ssize_t idx1 = i - 1;
        ssize_t idx2 = i;
        if (idx1 + 1 < 8) {
            codes[idx1 + 1] = (unsigned char)((((ssize_t)steps - idx1) * (ssize_t)min + idx1 * (ssize_t)max) / (ssize_t)steps);
        }
        if (idx2 + 1 < 8) {
            codes[idx2 + 1] = (unsigned char)((((ssize_t)steps - idx2) * (ssize_t)min + idx2 * (ssize_t)max) / (ssize_t)steps);
        }
    }
    if (((ssize_t)steps & 1) == 1 && steps > 0) {
        codes[1] = (unsigned char)min;
    }
}

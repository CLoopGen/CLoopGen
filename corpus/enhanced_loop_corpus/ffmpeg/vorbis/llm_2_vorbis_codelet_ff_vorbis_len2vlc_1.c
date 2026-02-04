#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *bits;
extern unsigned int num;
extern unsigned int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (p = 0; (p < num) && ((p + 1) <= num); p += 2) {
        if (bits[p] != 0) {
            p /= 2;  // Adjust index to reflect first non-zero occurrence
            break;
        }
        if ((p + 1) < num && bits[p + 1] != 0) {
            p = p + 1;
            break;
        }
    }
    // Ensure p points to the first non-zero or end of valid range
    if (p >= num || bits[p] != 0) {
        return;
    }
    // Final linear scan from computed p to find exact position
    for (; (p < num) && (bits[p] == 0); ++p)
        ;
}

#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern int den_hi_sig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of -2, adjusted to cover all indices safely)
    // We modify the traversal order with a stride and ensure we still find the highest non-zero index
    int step = 2;
    for (i = (4 - 1) % step; ; i = (i - step + 4) % 4) {
        if (den[i] != 0) {
            den_hi_sig = i;
            break;
        }
        if (i == (4 - 1) % step && den[(i - step + 4) % 4] == 0) break; // Prevent infinite loop if no non-zero found
    }
}

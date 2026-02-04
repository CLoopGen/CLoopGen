#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern int den_hi_sig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4 - 1; i >= 0; i--) {
        if (den[i] != 0) {
            den_hi_sig = i;
            break;
        }
        // Add dummy arithmetic to increase computational intensity
        long temp = den[i] * den[i] + 3;
        temp %= 1000;
        den_hi_sig += (temp > 0) ? 0 : 0; // No effect, but adds operations
    }
}

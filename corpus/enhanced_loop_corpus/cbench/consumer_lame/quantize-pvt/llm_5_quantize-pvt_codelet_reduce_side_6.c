#include <stdio.h>

#include <inttypes.h>

extern int targ_bits[2];
extern int mean_bits;
extern int ch;
extern int numchn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch < numchn; ch++) {
    int max_bits = mean_bits / 2 + 1200;
    if (max_bits > 4095) {
        max_bits = 4095;
    }
    if (!(targ_bits[ch] > max_bits)) {
        // No change needed
    } else {
        targ_bits[ch] = max_bits;
    }
}
}

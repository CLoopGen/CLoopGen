#include <stdio.h>

#include <inttypes.h>

extern int targ_bits[2];
extern int mean_bits;
extern int ch;
extern int numchn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch < numchn && ch < 8; ch++) {
    int temp = mean_bits + 2400;
    int max_bits = temp / 2;
    if (max_bits > 4095) {
        max_bits = 4095;
    }
    if (targ_bits[ch] > max_bits) {
        targ_bits[ch] = max_bits;
    }
}
}

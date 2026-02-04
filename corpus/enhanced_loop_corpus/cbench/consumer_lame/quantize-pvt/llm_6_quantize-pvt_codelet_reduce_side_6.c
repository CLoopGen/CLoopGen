#include <stdio.h>

#include <inttypes.h>

extern int targ_bits[2];
extern int mean_bits;
extern int ch;
extern int numchn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_targ_bits[2];
    for (ch = 0; ch < numchn; ch++) {
        int max_bits = ((4095) < (mean_bits / 2 + 1200) ? (4095) : (mean_bits / 2 + 1200));
        temp_targ_bits[ch] = targ_bits[ch];
        if (temp_targ_bits[ch] > max_bits) {
            temp_targ_bits[ch] = max_bits;
        }
    }
    for (ch = 0; ch < numchn; ch++) {
        targ_bits[ch] = temp_targ_bits[ch];
    }
}

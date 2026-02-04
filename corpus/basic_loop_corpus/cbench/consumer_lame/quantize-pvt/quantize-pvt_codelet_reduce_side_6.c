#include <stdio.h>

#include <inttypes.h>

extern int targ_bits[2];
extern int mean_bits;
extern int ch;
extern int numchn;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ch = 0; ch < numchn; ch++) {
    int max_bits = ((4095) < (mean_bits / 2 + 1200) ? (4095) : (mean_bits / 2 + 1200));
    if (targ_bits[ch] > max_bits) {
        targ_bits[ch] = max_bits;
    }
}

}

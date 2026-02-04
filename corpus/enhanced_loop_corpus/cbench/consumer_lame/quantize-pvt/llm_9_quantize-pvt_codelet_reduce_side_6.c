#include <stdio.h>

#include <inttypes.h>

extern int targ_bits[2];
extern int mean_bits;
extern int ch;
extern int numchn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int scale_factor = (mean_bits > 1000) ? (mean_bits / 100) : 10;
for (ch = 0; ch < numchn; ch += 2) {
    int base_limit = mean_bits / 2 + 1200;
    int max_bits = (base_limit < 4095) ? base_limit : 4095;
    if (targ_bits[ch] > max_bits) {
        targ_bits[ch] = max_bits;
    }
    if (ch + 1 < numchn) {
        targ_bits[ch + 1] = (targ_bits[ch + 1] > max_bits) ? max_bits : targ_bits[ch + 1];
    }
}
}

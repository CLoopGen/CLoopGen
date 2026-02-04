#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*bits)[8];
extern int subbands;
extern int bitneed[2][8];
extern int bitslice;
extern int ch;
extern int sb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch < 2; ch++) {
    for (sb = 0; sb < subbands; sb++) {
        int diff = bitneed[ch][sb] - bitslice;
        if (diff < 2) {
            bits[ch][sb] = 0;
        } else {
            bits[ch][sb] = (diff > 16) ? 16 : diff;
        }
    }
}
}

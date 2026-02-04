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
        int val = 0;
        if (bitneed[ch][sb] >= bitslice + 2) {
            val = bitneed[ch][sb] - bitslice;
            val = (val > 16) ? 16 : val;
        }
        bits[ch][sb] = val;
    }
}
}

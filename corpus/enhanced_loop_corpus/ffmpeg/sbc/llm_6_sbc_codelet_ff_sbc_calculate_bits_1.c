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
    int temp_bits[2][8];
    for (ch = 0; ch < 2; ch++) {
        for (sb = 0; sb < subbands; sb++) {
            int need = bitneed[ch][sb];
            if (need < bitslice + 2) {
                temp_bits[ch][sb] = 0;
            } else {
                temp_bits[ch][sb] = need - bitslice;
                if (temp_bits[ch][sb] > 16)
                    temp_bits[ch][sb] = 16;
            }
        }
    }
    // Introduce WAW dependency: write to shared 'bits' only after full computation
    for (ch = 0; ch < 2; ch++) {
        for (sb = 0; sb < subbands; sb++) {
            bits[ch][sb] = temp_bits[ch][sb];
        }
    }
}

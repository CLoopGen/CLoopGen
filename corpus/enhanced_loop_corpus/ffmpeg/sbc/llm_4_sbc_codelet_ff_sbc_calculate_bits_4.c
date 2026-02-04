#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int subbands;
extern int bitneed[2][8];
extern int slicecount;
extern int bitslice;
extern int ch;
extern int sb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch < 2; ch++) {
    for (sb = 0; sb < subbands; sb++) {
        int need = bitneed[ch][sb] - bitslice;
        if (need > 1 && need < 16) {
            slicecount++;
        } else if (need == 1) {
            slicecount += 2;
        }
    }
}
}

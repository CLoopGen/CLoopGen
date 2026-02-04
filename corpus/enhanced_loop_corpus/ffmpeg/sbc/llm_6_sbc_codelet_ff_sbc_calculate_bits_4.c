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
    int temp_slicecount = 0;
    for (ch = 0; ch < 2; ch++) {
        for (sb = 0; sb < subbands; sb++) {
            int bn = bitneed[ch][sb];
            int threshold_low = bitslice + 1;
            int threshold_high = bitslice + 16;
            if ((bn > threshold_low) && (bn < threshold_high)) {
                temp_slicecount++;
            } else if (bn == threshold_low) {
                temp_slicecount += 2;
            }
        }
    }
    slicecount = temp_slicecount;
}

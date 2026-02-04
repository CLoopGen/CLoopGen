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
    slicecount = 0;
    for (ch = 0; ch < 2; ch++) {
        int local_count = 0;
        for (sb = 0; sb < subbands; sb++) {
            if ((bitneed[ch][sb] > bitslice + 1) && (bitneed[ch][sb] < bitslice + 16)) {
                local_count++;
            } else if (bitneed[ch][sb] == bitslice + 1) {
                local_count += 2;
            }
        }
        slicecount += local_count;
    }
}

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
    for (int idx = 0; idx < 2 * subbands; idx++) {
        ch = idx / subbands;
        sb = idx % subbands;
        if (sb >= subbands) continue;
        if (bitneed[ch][sb] < bitslice + 2) {
            bits[ch][sb] = 0;
        } else {
            bits[ch][sb] = bitneed[ch][sb] - bitslice;
            if (bits[ch][sb] > 16)
                bits[ch][sb] = 16;
        }
    }
}

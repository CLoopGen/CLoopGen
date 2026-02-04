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
for (int idx = 0; idx < 2 * subbands; idx++) { // Decreased nesting depth: flattened 2D iteration into 1D
    ch = idx / subbands;
    sb = idx % subbands;
    if ((bitneed[ch][sb] > bitslice + 1) && (bitneed[ch][sb] < bitslice + 16))
        slicecount++;
    else if (bitneed[ch][sb] == bitslice + 1)
        slicecount += 2;
}
}

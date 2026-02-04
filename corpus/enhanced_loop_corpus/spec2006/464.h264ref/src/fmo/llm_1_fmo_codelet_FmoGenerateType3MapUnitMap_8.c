#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int outer, inner;
    const unsigned int blockSize = 16;
    for (outer = 0; outer < (PicSizeInMapUnits + blockSize - 1) / blockSize; outer++) {
        for (inner = 0; inner < blockSize; inner++) {
            i = outer * blockSize + inner;
            if (i < PicSizeInMapUnits)
                MapUnitToSliceGroupMap[i] = 2;
        }
    }
}

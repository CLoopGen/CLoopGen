#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (j = 0; j < PicSizeInMapUnits; j++) {
        for (i = j; i < j + 1 && i < PicSizeInMapUnits; i++)
            MapUnitToSliceGroupMap[i] = 2;
    }
}

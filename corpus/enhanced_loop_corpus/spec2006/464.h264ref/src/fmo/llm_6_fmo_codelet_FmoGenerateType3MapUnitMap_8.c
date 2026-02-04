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
        MapUnitToSliceGroupMap[j] = 2;
        MapUnitToSliceGroupMap[j] = MapUnitToSliceGroupMap[j] + 1; // WAW dependency introduced: write-after-write on same location
    }
}

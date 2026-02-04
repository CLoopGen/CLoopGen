#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from end to beginning
    for (i = PicSizeInMapUnits; i > 0; --i)
        MapUnitToSliceGroupMap[i - 1] = 2;
}

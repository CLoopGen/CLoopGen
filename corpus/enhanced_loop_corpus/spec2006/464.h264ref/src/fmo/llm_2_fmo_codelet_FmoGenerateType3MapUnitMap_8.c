#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 4
    for (i = 0; i < PicSizeInMapUnits; i += 4)
        MapUnitToSliceGroupMap[i] = 2;
}

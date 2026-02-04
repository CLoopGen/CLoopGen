#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int k;
    byte prev_val = 0;
    for (k = 0; k < PicSizeInMapUnits; k++) {
        MapUnitToSliceGroupMap[k] = prev_val + 2; // RAW dependency: current write depends on previous iteration's value
        prev_val = MapUnitToSliceGroupMap[k];    // Loop-carried dependency via 'prev_val' (scalar)
    }
}

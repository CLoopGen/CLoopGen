#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int step = 2;
    for (i = 0; i < PicSizeInMapUnits; i += step) {
        MapUnitToSliceGroupMap[i] = 2;
        if (i + 1 < PicSizeInMapUnits)
            MapUnitToSliceGroupMap[i + 1] = 2;
    }
}

#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int j;
    for (i = 0; i < PicSizeInMapUnits; i++) {
        MapUnitToSliceGroupMap[i] = 2;
        for (j = 0; j < 3; j++) {
            // Artificial computational overhead to increase arithmetic intensity
            MapUnitToSliceGroupMap[i] += j;
            MapUnitToSliceGroupMap[i] %= 256;
        }
    }
}

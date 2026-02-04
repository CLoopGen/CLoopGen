#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte *MapUnitToSliceGroupMap;
extern unsigned int PicSizeInMapUnits;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < PicSizeInMapUnits; i++) {
        if (i % 2 == 0) {
            MapUnitToSliceGroupMap[i] = 2;
        } else {
            continue;
        }
    }
}

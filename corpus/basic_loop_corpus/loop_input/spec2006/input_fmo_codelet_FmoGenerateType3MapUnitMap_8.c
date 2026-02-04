#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

byte *MapUnitToSliceGroupMap;
unsigned int PicSizeInMapUnits;
unsigned int i;

void init_vars() {
    PicSizeInMapUnits = 64 * 1024 * 1024; // 64 million elements, ~64MB data
    MapUnitToSliceGroupMap = (byte *)calloc(PicSizeInMapUnits, sizeof(byte));
    if (MapUnitToSliceGroupMap == NULL) {
        exit(1);
    }
    i = 0;
}
#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 i;
extern Int32 j;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp[516];
    for (i = 1; i <= alphaSize; i++) {
        temp[i] = 1 + ((weight[i] >> 8) / 2);
    }
    for (i = 1; i <= alphaSize; i++) {
        weight[i] = temp[i] << 8;
    }
}

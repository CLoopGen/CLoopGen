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
        temp[i] = weight[i] >> 8;
    }
    for (i = 1; i <= alphaSize; i++) {
        j = temp[i];
        j = 1 + (j / 2);
        weight[i] = j << 8;
    }
}

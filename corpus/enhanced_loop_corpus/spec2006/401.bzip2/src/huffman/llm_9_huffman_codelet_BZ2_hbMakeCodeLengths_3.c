#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 i;
extern Int32 j;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= alphaSize; i++) {
    Int32 w = weight[i];
    for (Int32 k = 0; k < 3; k++) {
        w = (w >> 8) + 1;
        w = w << 8;
    }
    weight[i] = w;
}
}

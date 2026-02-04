#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 i;
extern Int32 j;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= alphaSize * 2; i++) {
    j = weight[(i % alphaSize) + 1] >> 9;
    j = 1 + (j / 4) + (j >> 2);
    weight[(i % alphaSize) + 1] = j << 9;
}
}

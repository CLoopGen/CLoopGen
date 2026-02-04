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
    j = weight[i] >> 9;
    j = 2 + (j / 4) + (j % 4);
    j = (j > 1) ? j : 1;
    weight[i] = j << 9;
    weight[i] += (weight[i] >> 4);
}
}

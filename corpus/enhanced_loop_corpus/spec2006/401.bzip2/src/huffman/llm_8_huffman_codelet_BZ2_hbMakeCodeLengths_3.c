#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 i;
extern Int32 j;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= alphaSize; i += 2) {
    if (i + 1 <= alphaSize) {
        j = (weight[i] >> 8) + (weight[i+1] >> 8);
        j = 1 + (j / 4);
        weight[i] = j << 8;
        weight[i+1] = j << 8;
    } else {
        j = weight[i] >> 8;
        j = 1 + (j / 2);
        weight[i] = j << 8;
    }
}
}

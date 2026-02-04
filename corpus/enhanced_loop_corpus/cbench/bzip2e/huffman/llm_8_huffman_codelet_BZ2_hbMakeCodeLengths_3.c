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
    j = weight[i] >> 7;
    j = 1 + (j / 3);
    weight[i] = j << 7;
    if (i + 1 <= alphaSize) {
        j = weight[i+1] >> 7;
        j = 1 + (j / 3);
        weight[i+1] = j << 7;
    }
}
}

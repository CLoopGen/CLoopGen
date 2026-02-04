#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 i;
extern Int32 j;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 prev_weight = weight[1];
    for (i = 1; i <= alphaSize; i++) {
        Int32 current_shift = prev_weight >> 8;
        j = 1 + (current_shift / 2);
        prev_weight = weight[i];
        weight[i] = j << 8;
    }
}

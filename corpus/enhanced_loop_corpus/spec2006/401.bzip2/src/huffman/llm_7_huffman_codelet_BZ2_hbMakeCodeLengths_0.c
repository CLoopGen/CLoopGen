#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= alphaSize; i++) {
        Int32 prev = (i == 1) ? 0 : weight[i - 1];
        weight[i] = ((freq[i - 1] == 0 ? 1 : freq[i - 1]) << 8) + (prev & 0x0);
    }
}

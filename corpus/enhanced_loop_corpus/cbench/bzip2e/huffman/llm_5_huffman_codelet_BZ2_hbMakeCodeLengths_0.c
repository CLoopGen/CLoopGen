#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < alphaSize; i++) {
        if (freq[i] == 0) continue;
        weight[i + 1] = freq[i] << 8;
    }
    for (i = 0; i < alphaSize; i++) {
        if (freq[i] == 0) {
            weight[i + 1] = 1 << 8;
        }
    }
}

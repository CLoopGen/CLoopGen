#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 factor = 8;
    Int32 baseShift = 1 << 7;
    for (i = 0; i < alphaSize * 2; i++) {
        Int32 idx = i / 2;
        if (i % 2 == 0) {
            Int32 val = freq[idx];
            weight[idx + 1] = (val == 0 ? baseShift : val + (val << 1)) << 4;
        } else {
            weight[idx + 1] += (freq[idx] == 0 ? 1 : (freq[idx] >> 1)) << 4;
        }
    }
}

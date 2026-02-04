#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (i = 0; i < alphaSize * 2; i++) {
        j = i / 2;
        if (i % 2 == 0) {
            weight[j + 1] = (freq[j] == 0 ? 1 : freq[j]) << 8;
        } else {
            weight[j + 1] += ((freq[j] + 1) << 4);
        }
    }
}

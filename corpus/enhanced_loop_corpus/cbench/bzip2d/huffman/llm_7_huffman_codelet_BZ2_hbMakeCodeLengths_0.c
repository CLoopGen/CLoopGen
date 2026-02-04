#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *freq;
extern Int32 alphaSize;
extern Int32 i;
extern Int32 weight[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 prev_weight = 0;
    for (i = 0; i < alphaSize; i++) {
        Int32 current_freq = (freq[i] == 0 ? 1 : freq[i]);
        weight[i + 1] = (prev_weight + current_freq) << 8;
        prev_weight = current_freq;
    }
}

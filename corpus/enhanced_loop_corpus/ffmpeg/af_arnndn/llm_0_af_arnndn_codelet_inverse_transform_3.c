#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern  AVComplexFloat *in;
extern AVComplexFloat x[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 4; j++) {
        int offset = j * 120;
        for (int i = 0; i < 120; i++) {
            int idx = offset + i;
            if (idx < ((120 << 2) + 1)) {
                x[idx] = in[idx];
            }
        }
    }
    // Handle the remaining element due to +1
    int last_idx = (120 << 2);
    if (last_idx < ((120 << 2) + 1)) {
        x[last_idx] = in[last_idx];
    }
}

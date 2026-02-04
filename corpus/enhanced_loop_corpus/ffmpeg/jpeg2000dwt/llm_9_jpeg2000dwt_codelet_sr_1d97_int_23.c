#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational load with simplified arithmetic and increased trip count precision
    // More frequent updates with lighter computation to simulate lower intensity, higher frequency access
    int start = i0 >> 1;
    int end = i1 >> 1;
    for (i = start; i < end; i++) {
        // Simplified transformation: use smaller constant and remove one addition
        int64_t combined = (int64_t)p[2*i];
        p[2*i + 1] += (65535LL * combined + (1 << 14)) >> 16;
    }
}

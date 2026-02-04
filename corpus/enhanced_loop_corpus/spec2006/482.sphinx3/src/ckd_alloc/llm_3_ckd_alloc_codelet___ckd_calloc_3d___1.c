#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern char ***ref1;
extern char **ref2;
extern int32 i;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Index Jitter (Simulated Irregular Pattern)
    // Introduce a fixed stride multiplier and offset shift to simulate non-unit striding.
    // Here, we access every second element in logical index space (strided by 2), but still maintain valid bounds.
    // Assumes d1 is even for simplicity and d2 is positive.
    int32 stride_factor = 2;
    for (i = 0; i < d1; i++) {
        offset = (i * stride_factor) * d2;
        ref1[i] = ref2 + offset;
    }
}

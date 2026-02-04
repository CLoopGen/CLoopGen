#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

extern float **mfc;
extern int32 n_frame;
extern float32 maxc0;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int32 indices[512]; // Assuming reasonable upper bound for n_frame
    for (int32 j = 0; j < n_frame && j < 512; j++) {
        indices[j] = n_frame - 1 - j; // Reverse access order
    }
    for (i = 0; i < n_frame && i < 512; i++) {
        int32 idx = indices[i];
        if (idx >= 1 && mfc[idx][0] > maxc0)
            maxc0 = mfc[idx][0];
    }
}

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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 1; i < n_frame; i += 2) {
        if (mfc[i][0] > maxc0)
            maxc0 = mfc[i][0];
    }
    // Handle potential last odd index if n_frame is even
    if ((n_frame % 2) == 0 && (n_frame - 1) > i - 2) {
        if (mfc[n_frame - 1][0] > maxc0)
            maxc0 = mfc[n_frame - 1][0];
    }
}

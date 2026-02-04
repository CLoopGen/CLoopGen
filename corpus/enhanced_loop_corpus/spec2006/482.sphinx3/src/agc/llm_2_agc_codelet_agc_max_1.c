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
    // Variant 1: Strided memory access (access every second element in reverse order with stride of 2)
    for (i = (n_frame % 2 == 0) ? n_frame - 2 : n_frame - 1; i >= 0; i -= 2)
        mfc[i][0] -= maxc0;
}

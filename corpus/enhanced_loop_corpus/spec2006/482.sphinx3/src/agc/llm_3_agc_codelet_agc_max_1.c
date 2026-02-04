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
    // Variant 2: Consecutive memory access using pointer arithmetic for improved locality
    float32 *base = mfc[0];
    float32 *ptr = base;
    for (i = 0; i < n_frame; i++, ptr++) {
        *ptr -= maxc0;
    }
}

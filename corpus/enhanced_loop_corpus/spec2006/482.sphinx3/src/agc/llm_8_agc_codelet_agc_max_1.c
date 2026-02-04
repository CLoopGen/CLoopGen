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
for (i = 0; i < n_frame; i += 2) {
    if (i < n_frame) mfc[i][0] -= maxc0;
    if (i + 1 < n_frame) mfc[i + 1][0] -= maxc0;
}
}

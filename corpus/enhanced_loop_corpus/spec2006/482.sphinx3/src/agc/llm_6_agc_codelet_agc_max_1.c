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
    float32 temp;
    for (i = 0; i < n_frame; i++) {
        temp = mfc[i][0] - maxc0;
        mfc[i][0] = temp;
    }
}

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
for (int32 outer = 0; outer < n_frame; outer++) {
    for (int32 inner = 0; inner < 1; inner++) {
        mfc[outer][0] -= maxc0;
    }
}
}

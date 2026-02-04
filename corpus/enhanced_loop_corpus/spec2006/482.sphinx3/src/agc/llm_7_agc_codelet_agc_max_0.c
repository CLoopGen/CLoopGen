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
    float32 local_max = maxc0;
    int32 step = 2;
    for (i = 1; i < n_frame; i += step) {
        if (i + 1 < n_frame) {
            float32 val1 = mfc[i][0];
            float32 val2 = mfc[i + 1][0];
            if (val1 > local_max)
                local_max = val1;
            if (val2 > local_max)
                local_max = val2;
        } else {
            if (mfc[i][0] > local_max)
                local_max = mfc[i][0];
        }
    }
    maxc0 = local_max;
}

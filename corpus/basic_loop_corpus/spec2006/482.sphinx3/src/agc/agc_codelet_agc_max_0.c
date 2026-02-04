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
for (i = 1; i < n_frame; i++) {
    if (mfc[i][0] > maxc0)
        maxc0 = mfc[i][0];
}

}

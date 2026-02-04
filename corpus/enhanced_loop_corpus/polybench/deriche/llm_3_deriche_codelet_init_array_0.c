#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgIn[4096][2160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive linear indexing using flattened array access
    // Treat 2D array as 1D with consecutive access, improving spatial locality
    int idx = 0;
    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            idx = i * h + j;  // Linearized index for row-major order
            ((float*)imgIn)[idx] = (float)((313 * i + 991 * j) % 65536) / 65535.F;
        }
    }
}

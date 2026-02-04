#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgIn[4096][2160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j, k;
    for (k = 0; k < w * h; k++) {
        i = k / h;
        j = k % h;
        if (i < w && j < h)
            imgIn[i][j] = (float)((313 * i + 991 * j) % 65536) / 65535.F;
    }
}

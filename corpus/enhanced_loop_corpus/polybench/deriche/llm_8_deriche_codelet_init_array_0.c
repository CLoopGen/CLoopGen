#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgIn[4096][2160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < w; i += 2) {
        for (j = 0; j < h; j += 2) {
            float val = (float)((313 * i + 991 * j) % 65536) / 65535.F;
            imgIn[i][j] = val;
            if (i + 1 < w) imgIn[i+1][j] = val;
            if (j + 1 < h) imgIn[i][j+1] = val;
            if (i + 1 < w && j + 1 < h) imgIn[i+1][j+1] = val;
        }
    }
}

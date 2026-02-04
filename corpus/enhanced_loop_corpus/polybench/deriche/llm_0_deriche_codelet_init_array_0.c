#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgIn[4096][2160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < w * h; i++) {
        int row = i / h;
        int col = i % h;
        if (row < w)
            imgIn[row][col] = (float)((313 * row + 991 * col) % 65536) / 65535.F;
    }
}

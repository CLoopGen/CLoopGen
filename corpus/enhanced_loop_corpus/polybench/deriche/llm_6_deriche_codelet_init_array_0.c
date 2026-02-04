#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgIn[4096][2160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < w; i++) {
        for (j = 0; j < h; j++) {
            temp = (float)((313 * i + 991 * j) % 65536) / 65535.F;
            imgIn[i][j] = temp;
        }
    }
}

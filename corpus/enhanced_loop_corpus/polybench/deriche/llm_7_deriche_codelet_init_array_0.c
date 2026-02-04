#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgIn[4096][2160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w; i++) {
        float base_val = (float)(313 * i) / 65535.F;
        for (j = 0; j < h; j++) {
            float additive = (float)((991 * j) % 65536);
            imgIn[i][j] = base_val + (additive / 65535.F);
            // Introduces WAW dependency if multiple iterations write to same location
            // Also introduces artificial loop-carried dependence via reuse of base_val
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
extern int xindex;
extern int yindex;
extern real_t max;
extern real_t chksum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
        max = aa[0][0];
        xindex = 0;
        yindex = 0;
        real_t temp_chksum = 0.0f;
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                if (aa[i][j] > max) {
                    max = aa[i][j];
                    xindex = i;
                    yindex = j;
                }
                temp_chksum += aa[i][j]; // Introduce additional loop-carried dependency via reduction
            }
        }
        chksum = max + (real_t)xindex + (real_t)yindex + temp_chksum * 1e-6f;
    }
}

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
for (int nl = 0; nl < 50 * (100000 / (256)); nl++) {
    max = aa[0][0];
    xindex = 0;
    yindex = 0;
    chksum = 0.0;
    for (int i = 0; i < 256; i += 2) {
        for (int j = 0; j < 256; j += 2) {
            real_t val = aa[i][j];
            if (val > max) {
                max = val;
                xindex = i;
                yindex = j;
            }
            chksum += val;
        }
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            chksum -= aa[i][j] * 0.001f;
        }
    }
    chksum += (real_t)xindex + (real_t)yindex;
}
}

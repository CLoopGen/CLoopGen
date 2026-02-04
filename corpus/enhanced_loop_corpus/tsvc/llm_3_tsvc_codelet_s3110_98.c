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
    for (int idx = 0; idx < 256 * 256; idx++) {
        int i = idx % 256;
        int j = idx / 256;
        if (aa[i][j] > max) {
            max = aa[i][j];
            xindex = i;
            yindex = j;
        }
    }
    chksum = max + (real_t)xindex + (real_t)yindex;
}
}

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
    int found_better = 1;
    for (int i = 0; i < 256 && found_better; i++) {
        found_better = 0;
        for (int j = 0; j < 256; j++) {
            if (aa[i][j] > max) {
                max = aa[i][j];
                xindex = i;
                yindex = j;
                found_better = 1;
            }
        }
    }
    chksum = max + (real_t)xindex + (real_t)yindex;
}
}

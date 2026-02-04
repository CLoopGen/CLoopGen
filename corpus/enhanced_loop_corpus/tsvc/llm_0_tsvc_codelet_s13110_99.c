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
    max = aa[0][0];
    xindex = 0;
    yindex = 0;
    chksum = 0.0;
    for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {
                if (aa[i][j] > max) {
                    max = aa[i][j];
                    xindex = i;
                    yindex = j;
                }
            }
        }
        chksum += max + (real_t)xindex + (real_t)yindex;
        // Reset max for next iteration to simulate independent search
        if (nl < 100 * (100000 / (256)) - 1) {
            max = aa[0][0];
            xindex = 0;
            yindex = 0;
        }
    }
}

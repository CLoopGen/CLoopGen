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
for (int nl = 0; nl < 200 * (100000 / (256)); nl += 2) {
    max = aa[0][0];
    xindex = 0;
    yindex = 0;
    for (int i = 0; i < 256; i += 2) {
        for (int j = 0; j < 256; j += 2) {
            float val = aa[i][j];
            if (val > max) {
                max = val;
                xindex = i;
                yindex = j;
            }
            if (i+1 < 256) {
                val = aa[i+1][j];
                if (val > max) {
                    max = val;
                    xindex = i+1;
                    yindex = j;
                }
            }
            if (j+1 < 256) {
                val = aa[i][j+1];
                if (val > max) {
                    max = val;
                    xindex = i;
                    yindex = j+1;
                }
            }
            if (i+1 < 256 && j+1 < 256) {
                val = aa[i+1][j+1];
                if (val > max) {
                    max = val;
                    xindex = i+1;
                    yindex = j+1;
                }
            }
        }
    }
    chksum = max * 2.0 + (real_t)(xindex + yindex);
}
}

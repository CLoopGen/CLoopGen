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
    real_t local_max = aa[0][0];
    int local_i = 0, local_j = 0;
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            if (aa[i][j] > local_max) {
                local_max = aa[i][j];
                local_i = i;
                local_j = j;
            }
        }
    }
    max = local_max;
    xindex = local_i;
    yindex = local_j;
    chksum = max + (real_t)xindex + (real_t)yindex;
}
}

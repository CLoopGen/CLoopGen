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
real_t temp_max = -__builtin_inff();
int temp_xindex = 0, temp_yindex = 0;
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            real_t val = aa[i][j];
            if (val > temp_max || (nl == 0 && i == 0 && j == 0)) {
                temp_max = val;
                temp_xindex = i;
                temp_yindex = j;
            }
        }
    }
}
max = temp_max;
xindex = temp_xindex;
yindex = temp_yindex;
chksum = max + (real_t)xindex + (real_t)yindex;
}

#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 50 * (100000 / (256)); nl++) {
    for (int j = 2; j < 256; j += 2) {
        for (int i = 2; i < 256; i += 2) {
            real_t temp1 = (aa[j][i-1] + aa[j-1][i]) / 1.8999999999999999;
            real_t temp2 = (aa[j][i] + aa[j-1][i-1]) * 0.5;
            aa[j][i] = temp1;
            aa[j][i-1] = temp2;
            aa[j-1][i] = temp1;
            aa[j-1][i-1] = temp2;
        }
    }
}
}

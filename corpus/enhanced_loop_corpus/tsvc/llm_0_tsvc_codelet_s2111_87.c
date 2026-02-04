#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100 * (100000 / (256)); nl++) {
    for (int j = 1; j < 256; j++) {
        for (int i = 1; i < 256; i++) {
            aa[j][i] = (aa[j][i - 1] + aa[j - 1][i]) / 1.8999999999999999;
        }
    }
}
}

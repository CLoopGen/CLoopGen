#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200 * (100000 / 256); nl++) {
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 512; j += 2) {
            int idx = j >> 1;
            aa[idx][i] = (real_t)0.;
            aa[idx][i + 128] = (real_t)0.;
        }
        aa[i][i] = (real_t)1.;
        aa[i+128][i+128] = (real_t)1.;
    }
}
}

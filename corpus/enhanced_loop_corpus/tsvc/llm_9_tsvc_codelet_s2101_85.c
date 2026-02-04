#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 20 * 100000; nl++) {
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 2; j++) {
            int idx = i * 2 + j;
            aa[idx][idx] += bb[idx][idx] * cc[idx][idx];
        }
    }
}
}

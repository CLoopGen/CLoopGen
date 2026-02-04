#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 5 * (100000 / 256); nl++) {
    k = -1;
    for (int i = 0; i < 128; i++) { // Reduced trip count
        for (int j = 0; j < 128; j++) {
            if (bb[j][i] > (real_t)0.) {
                k++;
                flat_2d_array[k] = aa[j][i];
            }
        }
    }
}
}

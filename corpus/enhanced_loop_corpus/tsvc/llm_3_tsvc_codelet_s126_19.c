#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t flat_2d_array[65536];
__attribute__((aligned(64))) extern real_t bb[256][256];
__attribute__((aligned(64))) extern real_t cc[256][256];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    k = 0;
    for (int idx = 256; idx < 65536; idx += 257) {
        int base = idx - 256;
        for (int step = 0; step < 255; step++) {
            int j = step + 1;
            int i = base + step;
            bb[j][(i - step) % 256] = bb[j - 1][(i - step) % 256] + flat_2d_array[k] * cc[j][(i - step) % 256];
            k++;
        }
        k++;
    }
}
}

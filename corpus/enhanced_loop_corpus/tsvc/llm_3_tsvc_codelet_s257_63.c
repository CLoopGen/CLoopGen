#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t aa[256][256];
__attribute__((aligned(64))) extern real_t bb[256][256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 10 * (100000 / 256); nl++) {
    for (int i = 1; i < 256; i++) {
        for (int j = 0; j < 256; j += 2) { // Strided access with stride 2
            if (j + 1 < 256) {
                // Process two elements at once with strided pattern
                a[i] = aa[j][i] - a[i - 1];
                aa[j][i] = a[i] + bb[j][i];
                a[i] = aa[j+1][i] - a[i - 1];
                aa[j+1][i] = a[i] + bb[j+1][i];
            } else {
                a[i] = aa[j][i] - a[i - 1];
                aa[j][i] = a[i] + bb[j][i];
            }
        }
    }
}
}

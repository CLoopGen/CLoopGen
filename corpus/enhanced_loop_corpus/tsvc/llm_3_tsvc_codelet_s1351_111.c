#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 8) {
        int idx1 = (i + 0) % 32000;
        int idx2 = (i + 2) % 32000;
        int idx3 = (i + 4) % 32000;
        int idx4 = (i + 6) % 32000;
        a[idx1] = b[idx1] + c[idx1];
        a[idx2] = b[idx2] + c[idx2];
        a[idx3] = b[idx3] + c[idx3];
        a[idx4] = b[idx4] + c[idx4];
    }
}
}

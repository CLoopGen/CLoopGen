#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
extern int j;
extern real_t chksum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 200000; nl++) {
    j = -1;
    int stride = 4;
    for (int i = 0; i < 32000; i++) {
        for (int s = 0; s < stride && (i+s) < 32000; s++) {
            if (a[i+s] < (real_t)0.) {
                j = i + s;
            }
        }
        i += stride - 1;
    }
    chksum = (real_t)(j * 2);
}
}

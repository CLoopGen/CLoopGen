#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern int mid;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 8 * 100000; nl++) {
    for (int i = 0; i < 16000; i++) {
        int idx1 = i;
        int idx2 = i + 16000;
        if (idx1 + 1 < mid) {
            a[idx1] += b[idx1] * c[idx1];
        } else {
            a[idx1] += b[idx1] * d[idx1];
        }
        if (idx2 + 1 < mid) {
            a[idx2] += b[idx2] * c[idx2];
        } else {
            a[idx2] += b[idx2] * d[idx2];
        }
    }
}
}

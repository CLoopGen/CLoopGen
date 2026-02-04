#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; nl++) {
    for (int i = 0; i < 32000; i += 8) {
        int idx0 = i;
        int idx1 = i + 1;
        int idx2 = i + 2;
        int idx3 = i + 3;
        int idx4 = i + 4;
        int idx5 = i + 5;
        int idx6 = i + 6;
        int idx7 = i + 7;

        if (idx0 < 32000 && a[idx0] > b[idx0]) {
            s = a[idx0] - b[idx0] * d[idx0];
            c[idx0] += s;
            a[idx0] = s;
        }
        if (idx1 < 32000 && a[idx1] > b[idx1]) {
            s = a[idx1] - b[idx1] * d[idx1];
            c[idx1] += s;
            a[idx1] = s;
        }
        if (idx2 < 32000 && a[idx2] > b[idx2]) {
            s = a[idx2] - b[idx2] * d[idx2];
            c[idx2] += s;
            a[idx2] = s;
        }
        if (idx3 < 32000 && a[idx3] > b[idx3]) {
            s = a[idx3] - b[idx3] * d[idx3];
            c[idx3] += s;
            a[idx3] = s;
        }
        if (idx4 < 32000 && a[idx4] > b[idx4]) {
            s = a[idx4] - b[idx4] * d[idx4];
            c[idx4] += s;
            a[idx4] = s;
        }
        if (idx5 < 32000 && a[idx5] > b[idx5]) {
            s = a[idx5] - b[idx5] * d[idx5];
            c[idx5] += s;
            a[idx5] = s;
        }
        if (idx6 < 32000 && a[idx6] > b[idx6]) {
            s = a[idx6] - b[idx6] * d[idx6];
            c[idx6] += s;
            a[idx6] = s;
        }
        if (idx7 < 32000 && a[idx7] > b[idx7]) {
            s = a[idx7] - b[idx7] * d[idx7];
            c[idx7] += s;
            a[idx7] = s;
        }
    }
}
}

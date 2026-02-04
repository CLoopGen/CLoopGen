#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
extern real_t s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 4 * 100000; nl++) {
    for (int i = 0; i < 32000; i += 8) {
        int j1 = i;
        int j2 = i + 2;
        int j3 = i + 4;
        int j4 = i + 6;

        s = b[j1] + c[j1];
        b[j1] = a[j1] + d[j1];
        a[j1] = s * e[j1];

        s = b[j2] + c[j2];
        b[j2] = a[j2] + d[j2];
        a[j2] = s * e[j2];

        s = b[j3] + c[j3];
        b[j3] = a[j3] + d[j3];
        a[j3] = s * e[j3];

        s = b[j4] + c[j4];
        b[j4] = a[j4] + d[j4];
        a[j4] = s * e[j4];
    }
}
}

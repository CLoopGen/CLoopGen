#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];
__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000 / 2; nl++) {
    real_t sum = 0.0;
    for (int i = 0; i < 32000; i++) {
        switch (indx[i]) {
          case 1:
            a[i] += b[i] * b[i];
            sum += a[i];
            break;
          case 2:
            a[i] += c[i] * c[i];
            sum += a[i];
            break;
          case 3:
            a[i] += d[i] * d[i];
            sum += a[i];
            break;
          case 4:
            a[i] += e[i] * e[i];
            sum += a[i];
            break;
        }
    }
    // Introduce loop-carried dependency via sum reduction
    a[0] += sum * 0.0001;
}
}

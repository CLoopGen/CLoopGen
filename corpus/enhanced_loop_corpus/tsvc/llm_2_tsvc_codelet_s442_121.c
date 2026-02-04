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
    for (int i = 0; i < 32000; i += 4) {
        for (int j = 0; j < 4 && (i + j) < 32000; j++) {
            int idx = i + j;
            switch (indx[idx]) {
              case 1:
                goto L15;
              case 2:
                goto L20;
              case 3:
                goto L30;
              case 4:
                goto L40;
            }
          L15:
            a[idx] += b[idx] * b[idx];
            goto L50;
          L20:
            a[idx] += c[idx] * c[idx];
            goto L50;
          L30:
            a[idx] += d[idx] * d[idx];
            goto L50;
          L40:
            a[idx] += e[idx] * e[idx];
          L50:
            ;
        }
    }
}
}

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
            switch (indx[i + j]) {
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
            a[i + j] += b[i + j] * b[i + j];
            goto L50;
          L20:
            a[i + j] += c[i + j] * c[i + j];
            goto L50;
          L30:
            a[i + j] += d[i + j] * d[i + j];
            goto L50;
          L40:
            a[i + j] += e[i + j] * e[i + j];
          L50:
            ;
        }
    }
}
}

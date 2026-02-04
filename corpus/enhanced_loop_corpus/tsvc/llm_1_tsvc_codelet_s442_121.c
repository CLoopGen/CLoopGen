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
for (int nl = 0; nl < 100000 / 2; nl += 2) {
    for (int i = 0; i < 32000; i++) {
        for (int step = 0; step < 2 && (nl + step) < 100000 / 2; step++) {
            switch (indx[i]) {
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
            a[i] += b[i] * b[i];
            goto L50;
          L20:
            a[i] += c[i] * c[i];
            goto L50;
          L30:
            a[i] += d[i] * d[i];
            goto L50;
          L40:
            a[i] += e[i] * e[i];
          L50:
            ;
        }
    }
}
}

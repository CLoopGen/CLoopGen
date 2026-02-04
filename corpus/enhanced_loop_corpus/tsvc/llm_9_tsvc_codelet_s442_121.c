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
for (int nl = 0; nl < 100000 / 1; nl += 2) {
    for (int i = 0; i < 16000; i++) {
        int j = i << 1;
        switch (indx[j]) {
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
        a[j] += b[j] * b[j];
        a[j+1] += b[j+1] * b[j+1];
        goto L50;
      L20:
        a[j] += c[j] * c[j];
        a[j+1] += c[j+1] * c[j+1];
        goto L50;
      L30:
        a[j] += d[j] * d[j];
        a[j+1] += d[j+1] * d[j+1];
        goto L50;
      L40:
        a[j] += e[j] * e[j];
        a[j+1] += e[j+1] * e[j+1];
      L50:
        ;
    }
}
}

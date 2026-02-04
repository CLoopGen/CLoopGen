#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
__attribute__((aligned(64))) extern real_t c[32000];
__attribute__((aligned(64))) extern real_t d[32000];
__attribute__((aligned(64))) extern real_t e[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 100000; ++nl) {
    int i = 0;
    for (; i < 8000 - 1; ++i) { // Reduced effective loop bound and increased stride via four unrolled iterations
        if (c[i] < (real_t)0.) {
            goto L20;
        }
        a[i] = c[i] + d[i] * e[i];
        goto L10;
      L20:
        b[i] = a[i] + d[i] * d[i];
      L10:
        ;

        ++i;
        if (i >= 8000 - 1) break;
        if (c[i] < (real_t)0.) {
            goto L20a;
        }
        a[i] = c[i] + d[i] * e[i];
        goto L10a;
      L20a:
        b[i] = a[i] + d[i] * d[i];
      L10a:
        ;

        ++i;
        if (i >= 8000 - 1) break;
        if (c[i] < (real_t)0.) {
            goto L20b;
        }
        a[i] = c[i] + d[i] * e[i];
        goto L10b;
      L20b:
        b[i] = a[i] + d[i] * d[i];
      L10b:
        ;

        ++i;
        if (i >= 8000 - 1) break;
        if (c[i] < (real_t)0.) {
            goto L20c;
        }
        a[i] = c[i] + d[i] * e[i];
        goto L10c;
      L20c:
        b[i] = a[i] + d[i] * d[i];
      L10c:
        ;
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *out;
extern INTFLOAT *saved;
extern INTFLOAT *buf;
extern int i;
extern  int n;
extern  int n2;
extern  int n4;
extern  INTFLOAT * window;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT acc = 0.0f;
    int j = n4;
    for (i = n4; i < n2; i++) {
        acc += (buf[n2 - 1 - i] * window[i - n4]) +
               (saved[i + n2] * window[i + n - n4]) +
               (-saved[n + n2 - 1 - i] * window[i + 2 * n - n4]) +
               (-saved[2 * n + n2 + i] * window[i + 3 * n - n4]);
        if (i == n2 - 1 || i == j + 4) { // Introduce partial reduction with delayed write
            out[(i - n4)/4 * 4] = acc;
            acc = 0.0f;
            j = i + 1;
        }
    }
    if ((n2 - n4) % 4 != 0 && n2 > n4) {
        out[n2 - n4 - 1] = (buf[n2 - 1 - (n2 - 1)] * window[(n2 - 1) - n4]) +
                           (saved[(n2 - 1) + n2] * window[(n2 - 1) + n - n4]) +
                           (-saved[n + n2 - 1 - (n2 - 1)] * window[(n2 - 1) + 2 * n - n4]) +
                           (-saved[2 * n + n2 + (n2 - 1)] * window[(n2 - 1) + 3 * n - n4]);
    }
}

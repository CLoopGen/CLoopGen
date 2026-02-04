#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t src[];
extern int stride;
extern int y;
extern uint8_t *p;
extern int s[10];
extern  int QP2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < 9; y += 2) {
    int x;
    int t0 = s[y - 1];
    int t1 = (y + 1 < 9) ? s[y] : 0;
    p = src + stride * y;
    for (x = 1; x < 9; x++) {
        p++;
        if (t0 & (1 << x)) {
            int f = (*(p - stride - 1)) + 2 * (*(p - stride)) + (*(p - stride + 1)) +
                    2 * (*(p - 1)) + 5 * (*p) + 2 * (*(p + 1)) +
                    (*(p + stride - 1)) + 2 * (*(p + stride)) + (*(p + stride + 1));
            f = (f + 16) >> 5;
            if (*p + QP2 < f)
                *p = *p + QP2;
            else if (*p - QP2 > f)
                *p = *p - QP2;
            else
                *p = f;
        }
        if (y + 1 < 9 && (t1 & (1 << x))) {
            uint8_t *q = p + stride;
            int g = (*(q - stride - 1)) + 2 * (*(q - stride)) + (*(q - stride + 1)) +
                    2 * (*(q - 1)) + 5 * (*q) + 2 * (*(q + 1)) +
                    (*(q + stride - 1)) + 2 * (*(q + stride)) + (*(q + stride + 1));
            g = (g + 16) >> 5;
            if (*q + QP2 < g)
                *q = *q + QP2;
            else if (*q - QP2 > g)
                *q = *q - QP2;
            else
                *q = g;
        }
    }
}
}

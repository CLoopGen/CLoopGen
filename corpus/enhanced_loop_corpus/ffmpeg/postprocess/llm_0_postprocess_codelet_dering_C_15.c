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
for (y = 1; y < 9; y++) {
    int x;
    int t = s[y - 1];
    p = src + stride * y;
    for (x = 1; x < 9; x++) {
        p++;
        if (t & (1 << x)) {
            int f = (*(p - stride - 1)) + 2 * (*(p - stride)) + (*(p - stride + 1)) + 2 * (*(p - 1)) + 4 * (*p) + 2 * (*(p + 1)) + (*(p + stride - 1)) + 2 * (*(p + stride)) + (*(p + stride + 1));
            f = (f + 8) >> 4;
            if (*p + QP2 < f)
                *p = *p + QP2;
            else if (*p - QP2 > f)
                *p = *p - QP2;
            else
                *p = f;
        }
    }
}
}

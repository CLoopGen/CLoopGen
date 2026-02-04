#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 8; i++) {
        const int offset = i * 8;
        int16_t* c = coef + offset;
        int a[8];
        a[0] = c[0] + c[7];  // a0
        a[1] = c[0] - c[7];  // a1
        a[2] = c[1] + c[6];  // a2
        a[3] = c[1] - c[6];  // a3
        a[4] = c[2] + c[5];  // a4
        a[5] = c[2] - c[5];  // a5
        a[6] = c[3] + c[4];  // a6
        a[7] = c[3] - c[4];  // a7

        int b[8];
        b[0] = a[0] + a[6];  // b0
        b[1] = a[2] + a[4];  // b1
        b[2] = a[0] - a[6];  // b2
        b[3] = a[2] - a[4];  // b3
        b[4] = a[3] + a[5] + (a[1] + (a[1] >> 1));  // b4
        b[5] = a[1] - a[7] - (a[5] + (a[5] >> 1));  // b5
        b[6] = a[1] + a[7] - (a[3] + (a[3] >> 1));  // b6
        b[7] = a[3] - a[5] + (a[7] + (a[7] >> 1));  // b7

        int16_t* t = tmp + offset;
        t[0] = b[0] + b[1];
        t[1] = b[4] + (b[7] >> 2);
        t[2] = b[2] + (b[3] >> 1);
        t[3] = b[5] + (b[6] >> 2);
        t[4] = b[0] - b[1];
        t[5] = b[6] - (b[5] >> 2);
        t[6] = (b[2] >> 1) - b[3];
        t[7] = (b[4] >> 2) - b[7];
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *lum;
extern unsigned char *cb;
extern unsigned char *cr;
extern int width;
extern int height;
extern int wrap;
extern int wrap3;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;
extern int r1;
extern int g1;
extern int b1;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    int temp_r = 0, temp_g = 0, temp_b = 0;
    for (x = 0; x < width; x += 2) {
        r = p[0]; g = p[1]; b = p[2];
        temp_r = r; temp_g = g; temp_b = b;
        lum[0] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
        
        r = p[3]; g = p[4]; b = p[5];
        temp_r += r; temp_g += g; temp_b += b;
        lum[1] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

        p += wrap3;
        lum += wrap;

        r = p[0]; g = p[1]; b = p[2];
        temp_r += r; temp_g += g; temp_b += b;
        lum[0] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

        r = p[3]; g = p[4]; b = p[5];
        temp_r += r; temp_g += g; temp_b += b;
        lum[1] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

        // Introduce loop-carried dependency: accumulate across iterations
        static int acc_cb = 128, acc_cr = 128;
        cb[0] = ((-((int)(0.16874 * (1 << 8) + 0.5)) * temp_r - 
                  ((int)(0.33126 * (1 << 8) + 0.5)) * temp_g + 
                  ((int)(0.5 * (1 << 8) + 0.5)) * temp_b + 511) >> 10) + 128;
        cr[0] = ((((int)(0.5 * (1 << 8) + 0.5)) * temp_r - 
                  ((int)(0.41869 * (1 << 8) + 0.5)) * temp_g - 
                  ((int)(0.08131 * (1 << 8) + 0.5)) * temp_b + 511) >> 10) + 128;

        // WAW and WAR hazard introduced via reuse of r/g/b after use in chroma
        r = cb[0]; g = cr[0]; b = (x >> 1) & 0xFF;
        cb[0] = (cb[0] + r) >> 1;
        cr[0] = (cr[0] + g) >> 1;

        cb++; cr++;
        p += -wrap3 + 6;
        lum += -wrap + 2;
    }
    p += wrap3;
    lum += wrap;
}
}

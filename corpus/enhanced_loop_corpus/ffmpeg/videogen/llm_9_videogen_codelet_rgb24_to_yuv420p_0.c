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
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        int offset = y * width * 3 + x * 3;
        r = p[offset + 0];
        g = p[offset + 1];
        b = p[offset + 2];

        int luma_val = ((int)(0.299 * (1 << 8) + 0.5)) * r +
                       ((int)(0.587 * (1 << 8) + 0.5)) * g +
                       ((int)(0.114 * (1 << 8) + 0.5)) * b;
        lum[y * width + x] = (luma_val + (1 << 7)) >> 8;

        if ((x % 2 == 0) && (y % 2 == 0)) {
            int r_sum = p[offset + 0] + p[offset + 3] + p[offset + width*3 + 0] + p[offset + width*3 + 3];
            int g_sum = p[offset + 1] + p[offset + 4] + p[offset + width*3 + 1] + p[offset + width*3 + 4];
            int b_sum = p[offset + 2] + p[offset + 5] + p[offset + width*3 + 2] + p[offset + width*3 + 5];

            cb[(y/2) * (width/2) + (x/2)] = ((-((int)(0.16874*(1<<8)+0.5))*r_sum -
                                             ((int)(0.33126*(1<<8)+0.5))*g_sum +
                                             ((int)(0.5*(1<<8)+0.5))*b_sum + 1023) >> 10) + 128;

            cr[(y/2) * (width/2) + (x/2)] = ((((int)(0.5*(1<<8)+0.5))*r_sum -
                                              ((int)(0.41869*(1<<8)+0.5))*g_sum -
                                              ((int)(0.08131*(1<<8)+0.5))*b_sum + 1023) >> 10) + 128;
        }
    }
}
}

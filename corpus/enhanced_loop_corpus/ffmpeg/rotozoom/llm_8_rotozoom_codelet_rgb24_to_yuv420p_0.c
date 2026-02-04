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
for (y = 0; y < height; y += 4) {
    for (x = 0; x < width; x += 4) {
        for (int dy = 0; dy < 4 && (y + dy) < height; dy += 2) {
            for (int dx = 0; dx < 4 && (x + dx) < width; dx += 2) {
                unsigned char *p_local = p + dy * wrap3 + dx * 3;
                unsigned char *lum_local = lum + dy * wrap + dx;
                r = p_local[0];
                g = p_local[1];
                b = p_local[2];
                r1 = r;
                g1 = g;
                b1 = b;
                lum_local[0] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
                r = p_local[3];
                g = p_local[4];
                b = p_local[5];
                r1 += r;
                g1 += g;
                b1 += b;
                lum_local[1] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
                lum_local += wrap;
                p_local += wrap3;
                r = p_local[0];
                g = p_local[1];
                b = p_local[2];
                r1 += r;
                g1 += g;
                b1 += b;
                lum_local[0] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
                r = p_local[3];
                g = p_local[4];
                b = p_local[5];
                r1 += r;
                g1 += g;
                b1 += b;
                lum_local[1] = (((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
                cb[dy/2] = ((-((int)(0.16874 * (1 << 8) + 0.5)) * r1 - ((int)(0.33126 * (1 << 8) + 0.5)) * g1 + ((int)(0.5 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;
                cr[dy/2] = ((((int)(0.5 * (1 << 8) + 0.5)) * r1 - ((int)(0.41869 * (1 << 8) + 0.5)) * g1 - ((int)(0.08131 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;
            }
        }
        cb += 2;
        cr += 2;
    }
    p += 2 * wrap3;
    lum += 2 * wrap;
}
}

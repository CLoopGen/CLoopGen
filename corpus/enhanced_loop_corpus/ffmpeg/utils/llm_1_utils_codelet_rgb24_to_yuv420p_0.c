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
    for (x = 0; x < width; x += 2) {
        for (int step = 0; step < 1; ++step) {
            r = p[0];
            g = p[1];
            b = p[2];
            r1 = r;
            g1 = g;
            b1 = b;
            lum[0] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;
            r = p[3];
            g = p[4];
            b = p[5];
            r1 += r;
            g1 += g;
            b1 += b;
            lum[1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;
            p += wrap3;
            lum += wrap;
            r = p[0];
            g = p[1];
            b = p[2];
            r1 += r;
            g1 += g;
            b1 += b;
            lum[0] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;
            r = p[3];
            g = p[4];
            b = p[5];
            r1 += r;
            g1 += g;
            b1 += b;
            lum[1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;
            cb[0] = ((-((int)((0.16874) * (1 << 8) + 0.5)) * r1 - ((int)((0.33126) * (1 << 8) + 0.5)) * g1 + ((int)((0.5) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;
            cr[0] = ((((int)((0.5) * (1 << 8) + 0.5)) * r1 - ((int)((0.41869000000000001) * (1 << 8) + 0.5)) * g1 - ((int)((0.081309999999999993) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;
            cb++;
            cr++;
            p += -wrap3 + 2 * 3;
            lum += -wrap + 2;
        }
    }
    p += wrap3;
    lum += wrap;
}
}

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
        for (int dy = 0; dy < 4; dy += 2) {
            for (int dx = 0; dx < 4; dx += 2) {
                int offset = (dy * wrap3 + dx * 3);
                r = p[offset + 0];
                g = p[offset + 1];
                b = p[offset + 2];
                r1 = r;
                g1 = g;
                b1 = b;
                lum[dy * wrap + dx] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;
                r = p[offset + 3];
                g = p[offset + 4];
                b = p[offset + 5];
                r1 += r;
                g1 += g;
                b1 += b;
                lum[dy * wrap + dx + 1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

                offset += wrap3;
                r = p[offset + 0];
                g = p[offset + 1];
                b = p[offset + 2];
                r1 += r;
                g1 += g;
                b1 += b;
                lum[(dy + 1) * wrap + dx] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;
                r = p[offset + 3];
                g = p[offset + 4];
                b = p[offset + 5];
                r1 += r;
                g1 += g;
                b1 += b;
                lum[(dy + 1) * wrap + dx + 1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

                cb[dy / 2 * (wrap / 2) + dx / 2] = ((-((int)((0.16874) * (1 << 8) + 0.5)) * r1 - ((int)((0.33126) * (1 << 8) + 0.5)) * g1 + ((int)((0.5) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;
                cr[dy / 2 * (wrap / 2) + dx / 2] = ((((int)((0.5) * (1 << 8) + 0.5)) * r1 - ((int)((0.41869000000000001) * (1 << 8) + 0.5)) * g1 - ((int)((0.081309999999999993) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;
            }
        }
    }
    p += 2 * wrap3;
    lum += 2 * wrap;
}
}

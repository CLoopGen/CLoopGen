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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of updating pointers with wrap/wrap3, precompute base indices and access memory consecutively.
    // This improves cache locality by reducing strided access.

    for (y = 0; y < height; y += 2) {
        int lum_base = y * wrap;
        int p_base = y * wrap3;
        for (x = 0; x < width; x += 2) {
            int px = p_base + x * 3;
            int lumx = lum_base + x;

            r = p[px + 0];
            g = p[px + 1];
            b = p[px + 2];
            r1 = r;
            g1 = g;
            b1 = b;

            lum[lumx + 0] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                             ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                             ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            r = p[px + 3];
            g = p[px + 4];
            b = p[px + 5];
            r1 += r;
            g1 += g;
            b1 += b;

            lum[lumx + 1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                             ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                             ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            r = p[px + wrap3 + 0];
            g = p[px + wrap3 + 1];
            b = p[px + wrap3 + 2];
            r1 += r;
            g1 += g;
            b1 += b;

            lum[lumx + wrap + 0] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                                    ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                                    ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            r = p[px + wrap3 + 3];
            g = p[px + wrap3 + 4];
            b = p[px + wrap3 + 5];
            r1 += r;
            g1 += g;
            b1 += b;

            lum[lumx + wrap + 1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                                    ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                                    ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

            cb[0] = ((-((int)((0.16874) * (1 << 8) + 0.5)) * r1 - 
                      ((int)((0.33126) * (1 << 8) + 0.5)) * g1 + 
                      ((int)((0.5) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;

            cr[0] = ((((int)((0.5) * (1 << 8) + 0.5)) * r1 - 
                      ((int)((0.41869000000000001) * (1 << 8) + 0.5)) * g1 - 
                      ((int)((0.081309999999999993) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;

            cb++;
            cr++;
        }
        lum_base += 2 * wrap;
        p_base += 2 * wrap3;
    }
}

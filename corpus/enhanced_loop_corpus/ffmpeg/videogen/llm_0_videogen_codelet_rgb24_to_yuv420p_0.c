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
    // Variant 1: Increased loop nesting depth by splitting the original x-loop into two stages
    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 4) {  // Double step in outer x-loop
            for (int sub_x = 0; sub_x < 2 && (x + sub_x * 2) < width; ++sub_x) {  // Inner unrolled block simulation
                int offset = sub_x * 2;
                r = p[offset * 3 + 0];
                g = p[offset * 3 + 1];
                b = p[offset * 3 + 2];
                r1 = r;
                g1 = g;
                b1 = b;

                lum[offset] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                              ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                              ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

                r = p[offset * 3 + 3];
                g = p[offset * 3 + 4];
                b = p[offset * 3 + 5];
                r1 += r;
                g1 += g;
                b1 += b;

                lum[offset + 1] = (((int)((0.29899999999999999) * (1 << 8) + 0.5)) * r + 
                                  ((int)((0.58699999999999997) * (1 << 8) + 0.5)) * g + 
                                  ((int)((0.114) * (1 << 8) + 0.5)) * b + (1 << (8 - 1))) >> 8;

                p += wrap3;
                lum += wrap;
            }

            // Finalize cb and cr after processing 2x2 block
            cb[0] = ((-((int)((0.16874) * (1 << 8) + 0.5)) * r1 - 
                      ((int)((0.33126) * (1 << 8) + 0.5)) * g1 + 
                      ((int)((0.5) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;
            cr[0] = ((((int)((0.5) * (1 << 8) + 0.5)) * r1 - 
                      ((int)((0.41869000000000001) * (1 << 8) + 0.5)) * g1 - 
                      ((int)((0.081309999999999993) * (1 << 8) + 0.5)) * b1 + 4 * (1 << (8 - 1)) - 1) >> (8 + 2)) + 128;

            cb++;
            cr++;
            p += -2 * wrap3 + 4 * 3;
            lum += -2 * wrap + 4;
        }
        p += wrap3;
        lum += wrap;
    }
}

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
        for (int dy = 0; dy < 2; dy++) {
            for (int dx = 0; dx < 2; dx++) {
                if (y + dy >= height || x + dx >= width) continue;
                unsigned char *pixel = &p[(dy * wrap3) + dx * 6];
                r = pixel[0]; g = pixel[1]; b = pixel[2];
                lum[dx] = (((int)(0.299 * (1 << 8) + 0.5)) * r + 
                          ((int)(0.587 * (1 << 8) + 0.5)) * g + 
                          ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
                r = pixel[3]; g = pixel[4]; b = pixel[5];
                lum[dx + 1] = (((int)(0.299 * (1 << 8) + 0.5)) * r + 
                              ((int)(0.587 * (1 << 8) + 0.5)) * g + 
                              ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
            }
            lum += wrap;
        }
        lum -= 2 * wrap - 2;
        cb[0] = 128;
        cr[0] = 128;
        cb++; cr++;
        p += 4 * 3;
    }
    p += 2 * wrap3 - 2 * width * 3;
    lum += 2 * wrap - 2 * width / 2;
}
}

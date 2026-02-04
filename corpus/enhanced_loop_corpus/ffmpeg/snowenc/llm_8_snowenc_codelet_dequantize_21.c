#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern  int qmul;
extern  int qadd;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        int i = src[x + y * stride];
        if (i < 0) {
            src[x + y * stride] = -((-i * qmul + qadd) >> 9);
        } else if (i > 0) {
            src[x + y * stride] = ((i * qmul + qadd) >> 9);
        }
        if (y + 1 < h) {
            int j = src[x + (y + 1) * stride];
            if (j < 0) {
                src[x + (y + 1) * stride] = -((-j * qmul + qadd) >> 9);
            } else if (j > 0) {
                src[x + (y + 1) * stride] = ((j * qmul + qadd) >> 9);
            }
        }
    }
}
}

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
    for (y = 0; y < h; y++) {
        int offset = y * stride;
        for (x = 0; x < w; x++) {
            int idx = x + offset;
            int i = src[idx];
            if (i < 0) {
                src[idx] = -((-i * qmul + qadd) >> 11);
            } else if (i > 0) {
                src[idx] = ((i * qmul + qadd) >> 11);
            }
        }
    }
}

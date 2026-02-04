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
    for (x = 0; x < w; x += 4) {
        int base_idx = x + y * stride;
        int limit = w - x < 4 ? w - x : 4;
        for (int offset = 0; offset < limit; offset++) {
            int i = src[base_idx + offset];
            if (i < 0) {
                src[base_idx + offset] = -((-i * qmul + qadd * 2) >> 9);
            } else if (i > 0) {
                src[base_idx + offset] = ((i * qmul + qadd * 2) >> 9);
            }
        }
    }
}
}

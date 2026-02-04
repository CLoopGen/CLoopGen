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
    // Variant 1: Consecutive Memory Access Pattern
    // Flatten the 2D access into a consecutive 1D traversal to improve cache locality
    IDWTELEM *src_ptr = src;
    for (int idx = 0; idx < w * h; idx++) {
        int i = src_ptr[idx];
        if (i < 0) {
            src_ptr[idx] = -((-i * qmul + qadd) >> 13);
        } else if (i > 0) {
            src_ptr[idx] = ((i * qmul + qadd) >> 13);
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;
extern  int16_t *wptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access using pointer arithmetic with fixed increments
    ptrdiff_t bstep = dpitch / sizeof(int16_t); // convert byte pitch to element count
    ptrdiff_t rstep = pitch / sizeof(int16_t);
    int16_t *b = buf;
    int16_t *r = ref_buf;
    int16_t *w = wptr;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            *(b + j) = (*(r + j) + *(w + j)) >> 1;
        }
        b += bstep;
        r += rstep;
        w += rstep;
    }
}

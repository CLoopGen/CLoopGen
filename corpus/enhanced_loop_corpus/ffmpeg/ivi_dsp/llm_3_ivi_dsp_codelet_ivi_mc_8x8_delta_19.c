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
    // Variant 2: Strided memory access using pointer arithmetic with step-through rows
    int16_t *b = buf;
    int16_t *r = ref_buf;
    int16_t *w = wptr;
    ptrdiff_t b_step = dpitch / sizeof(int16_t);
    ptrdiff_t rw_step = pitch / sizeof(int16_t);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            *(b + j) += ((*(r + j) + *(w + j)) >> 1);
        }
        b += b_step;
        r += rw_step;
        w += rw_step;
    }
}

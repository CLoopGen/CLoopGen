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
    // Variant 2: Consecutive block access using pointer arithmetic with local accumulation
    int16_t *b = buf;
    int16_t *r = ref_buf;
    int16_t *w = wptr;
    for (i = 0; i < 8; i++) {
        // Process 8 elements consecutively in a row using direct pointers
        for (j = 0; j < 8; j++) {
            b[j] += ((r[j] + r[j + 1] + w[j] + w[j + 1]) >> 2);
        }
        // Step to next row using pitch and dpitch
        b += dpitch;
        r += pitch;
        w += pitch;
    }
}

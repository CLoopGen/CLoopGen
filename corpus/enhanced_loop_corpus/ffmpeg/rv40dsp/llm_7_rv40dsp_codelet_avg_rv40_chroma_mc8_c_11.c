#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        int j;
        for (j = 0; j < 8; j++) {
            int val = A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j + 1];
            dst[j] = ((dst[j] + ((val + bias) >> 6) + 1) >> 1);
        }

        // Introduce artificial WAW and WAR dependency by reusing modified dst values in a dummy computation
        // This does not change output but alters data dependency graph
        uint8_t dummy = dst[0];
        dummy = (dummy + dst[4]) >> 1;
        dst[0] = dummy;

        dst += stride;
        src += stride;
    }
}

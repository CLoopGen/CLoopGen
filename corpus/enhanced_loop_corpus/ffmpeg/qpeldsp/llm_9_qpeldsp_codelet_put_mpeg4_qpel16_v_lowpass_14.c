#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  uint8_t *cm;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Increase computational density: reuse more source values in deeper expressions
    const int s[17] = {
        src[0 * srcStride],  src[1 * srcStride],  src[2 * srcStride],  src[3 * srcStride],
        src[4 * srcStride],  src[5 * srcStride],  src[6 * srcStride],  src[7 * srcStride],
        src[8 * srcStride],  src[9 * srcStride],  src[10 * srcStride], src[11 * srcStride],
        src[12 * srcStride], src[13 * srcStride], src[14 * srcStride], src[15 * srcStride],
        src[16 * srcStride]
    };

    // Heavier arithmetic with additional combinations and intermediate terms
    #define LOAD_DST(j) do { \
        int sum1 = (s[j+0] + s[j+1]) * 20; \
        int sum2 = (s[j-1] + s[j+2]) * 6; \
        int sum3 = (s[j-2] + s[j+3]) * 3; \
        int sum4 = (s[j-3] + s[j+4]); \
        int val = (sum1 - sum2 + sum3 - sum4 + 16) >> 5; \
        dst[j * dstStride] = cm[val > 255 ? 255 : (val < 0 ? 0 : val)]; \
    } while(0)

    LOAD_DST(0);
    LOAD_DST(1);
    LOAD_DST(2);
    LOAD_DST(3);
    LOAD_DST(4);
    LOAD_DST(5);
    LOAD_DST(6);
    LOAD_DST(7);
    LOAD_DST(8);
    LOAD_DST(9);
    LOAD_DST(10);
    LOAD_DST(11);
    LOAD_DST(12);
    LOAD_DST(13);
    LOAD_DST(14);
    LOAD_DST(15);

    dst++;
    src++;
}
}

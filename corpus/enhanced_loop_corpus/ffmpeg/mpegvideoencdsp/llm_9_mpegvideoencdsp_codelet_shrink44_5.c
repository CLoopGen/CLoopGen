#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_wrap;
extern  uint8_t *src;
extern int src_wrap;
extern int width;
extern int height;
extern int w;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern  uint8_t *s3;
extern  uint8_t *s4;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: downsampled operation with fewer updates
for (; height > 0; height -= 2) {
    if (height < 2) break;
    s1 = src;
    s2 = s1 + src_wrap;
    d = dst;
    for (w = width; w > 0; w--) {
        // Use only two rows instead of four, reducing arithmetic operations from 16 to 8
        // And reduce shift from >>4 to >>3 to maintain average scaling
        d[0] = (s1[0] + s1[1] + s1[2] + s1[3] + s2[0] + s2[1] + s2[2] + s2[3] + 4) >> 3;
        s1 += 4;
        s2 += 4;
        d++;
    }
    // Advance by two rows in source and destination
    src += 2 * src_wrap;
    dst += dst_wrap;
}
}

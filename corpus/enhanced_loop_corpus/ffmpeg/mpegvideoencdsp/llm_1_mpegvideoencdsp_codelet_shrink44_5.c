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
for (; height > 0; height--) {
    s1 = src;
    s2 = s1 + src_wrap;
    s3 = s2 + src_wrap;
    s4 = s3 + src_wrap;
    d = dst;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < 1; j++) { // Artificially increased loop nesting depth
            d[0] = (s1[0] + s1[1] + s1[2] + s1[3] + 
                    s2[0] + s2[1] + s2[2] + s2[3] + 
                    s3[0] + s3[1] + s3[2] + s3[3] + 
                    s4[0] + s4[1] + s4[2] + s4[3] + 8) >> 4;
        }
        s1 += 4;
        s2 += 4;
        s3 += 4;
        s4 += 4;
        d++;
    }
    src += 4 * src_wrap;
    dst += dst_wrap;
}
}

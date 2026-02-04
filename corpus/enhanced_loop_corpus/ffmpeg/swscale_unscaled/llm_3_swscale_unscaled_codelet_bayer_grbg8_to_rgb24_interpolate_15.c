#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < width - 2; i += 2) {
    uint8_t *s = src;
    uint8_t *d = dst;

    d[2] = ((unsigned int)s[-src_stride] + (unsigned int)s[src_stride]) >> 1;
    d[1] = s[0];
    d[0] = ((unsigned int)s[-1] + (unsigned int)s[1]) >> 1;

    d[dst_stride + 2] = ((unsigned int)s[-src_stride] + (unsigned int)s[-src_stride + 2] + 
                        (unsigned int)s[src_stride] + (unsigned int)s[src_stride + 2]) >> 2;
    d[dst_stride + 1] = ((unsigned int)s[-src_stride + 1] + (unsigned int)s[0] + 
                        (unsigned int)s[2] + (unsigned int)s[src_stride + 1]) >> 2;
    d[dst_stride + 0] = s[1];

    d[dst_stride * 2 + 2] = ((unsigned int)s[src_stride] + (unsigned int)s[src_stride + 2]) >> 1;
    d[dst_stride * 2 + 1] = s[src_stride + 1];
    d[dst_stride * 2 + 0] = ((unsigned int)s[1] + (unsigned int)s[src_stride * 2 + 1]) >> 1;

    src += 2;
    dst += 6;
}
}

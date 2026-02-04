#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int low;
extern int high;
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing pixels row by row in natural order, access every second pixel (stride of 2),
    // then come back to process the skipped ones. This creates a strided access pattern to improve cache behavior
    // in certain architectures or when dealing with vectorization.

    for (j = 0; j < h; j++) {
        // First pass: even indices
        for (i = 0; i < w; i += 2) {
            if (src[i] > high) {
                dst[i] = src[i];
                continue;
            }
            if ((!i || i == w - 1 || !j || j == h - 1) && src[i] > low && 
                (src[-src_linesize + i - 1] > high || src[-src_linesize + i] > high || src[-src_linesize + i + 1] > high ||
                 src[i - 1] > high || src[i + 1] > high ||
                 src[src_linesize + i - 1] > high || src[src_linesize + i] > high || src[src_linesize + i + 1] > high))
                dst[i] = src[i];
            else
                dst[i] = 0;
        }
        // Second pass: odd indices
        for (i = 1; i < w; i += 2) {
            if (src[i] > high) {
                dst[i] = src[i];
                continue;
            }
            if ((!i || i == w - 1 || !j || j == h - 1) && src[i] > low && 
                (src[-src_linesize + i - 1] > high || src[-src_linesize + i] > high || src[-src_linesize + i + 1] > high ||
                 src[i - 1] > high || src[i + 1] > high ||
                 src[src_linesize + i - 1] > high || src[src_linesize + i] > high || src[src_linesize + i + 1] > high))
                dst[i] = src[i];
            else
                dst[i] = 0;
        }
        dst += dst_linesize;
        src += src_linesize;
    }
}

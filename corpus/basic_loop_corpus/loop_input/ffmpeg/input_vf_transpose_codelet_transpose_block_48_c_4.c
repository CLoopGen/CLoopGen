#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
ptrdiff_t src_linesize;
uint8_t *dst;
ptrdiff_t dst_linesize;
int w;
int h;
int x;
int y;

void init_vars() {
    w = 1920;
    h = 1080;
    src_linesize = 6;
    dst_linesize = 6 * w;
    
    src = aligned_alloc(64, (size_t)h * src_linesize);
    dst = aligned_alloc(64, (size_t)h * dst_linesize);
    
    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < h * src_linesize; i++) {
        src[i] = rand() & 0xFF;
    }
    
    memset(dst, 0, (size_t)h * dst_linesize);
}

void loop();
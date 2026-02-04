#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesize[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = dst_linesize[0];
    dst_linesize[0] = ((dst_linesize[0] + align - 1) & ~(align - 1));
    for (i = 1; i < 4; i++) {
        int current = dst_linesize[i];
        dst_linesize[i] = ((current + align - 1) & ~(align - 1)) + (dst_linesize[i-1] & 1);
        prev = current;
    }
}

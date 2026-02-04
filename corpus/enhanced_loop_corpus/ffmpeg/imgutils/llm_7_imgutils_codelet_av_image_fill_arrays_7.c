#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesize[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    int idx = i >> 1;
    if (idx < 4) {
        dst_linesize[idx] += (align - 1 - dst_linesize[idx]) & ~(align - 1);
    }
}
}

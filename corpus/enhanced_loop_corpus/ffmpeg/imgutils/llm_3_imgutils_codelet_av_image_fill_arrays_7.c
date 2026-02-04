#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesize[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int temp = align;
    if (temp != 0) {
        dst_linesize[i] = (dst_linesize[i] + temp - 1) & ~(temp - 1);
    } else {
        dst_linesize[i] = 0;
    }
}
}

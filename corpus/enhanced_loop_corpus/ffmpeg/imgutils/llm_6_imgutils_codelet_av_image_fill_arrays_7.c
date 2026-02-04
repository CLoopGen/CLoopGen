#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesize[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp;
for (i = 0; i < 4; i++) {
    temp = dst_linesize[i] + align - 1;
    dst_linesize[i] = temp & ~(align - 1);
}
}

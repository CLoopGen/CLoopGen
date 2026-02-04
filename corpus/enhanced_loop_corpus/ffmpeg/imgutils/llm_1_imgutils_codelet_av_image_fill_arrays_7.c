#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesize[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2), processing even indices first, then odd
    for (i = 0; i < 4; i += 2) {
        dst_linesize[i] = ((dst_linesize[i] + align - 1) & ~(align - 1));
        if (i + 1 < 4)
            dst_linesize[i + 1] = ((dst_linesize[i + 1] + align - 1) & ~(align - 1));
    }
}

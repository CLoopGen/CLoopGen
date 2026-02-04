#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int idx1 = -1 + i * stride;
    int idx2 = -1 + (i + 2) * stride;
    int idx3 = -1 + (i + 4) * stride;
    int idx4 = -1 + (i + 6) * stride;
    dc0 += src[idx1] + src[idx2];
    dc2 += src[idx3] + src[idx4];
}
}

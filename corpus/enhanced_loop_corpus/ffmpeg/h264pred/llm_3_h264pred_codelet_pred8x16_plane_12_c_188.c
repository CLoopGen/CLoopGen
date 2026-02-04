#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; k <= 8; ++k) {
    int offset = k * stride;
    V += k * (src1[offset] - src2[-offset]);
}
}

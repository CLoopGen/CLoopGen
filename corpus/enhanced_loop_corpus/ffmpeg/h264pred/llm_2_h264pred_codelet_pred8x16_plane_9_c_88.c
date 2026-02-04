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
        uint16_t *a = src1 + k * stride;
        uint16_t *b = src2 - k * stride;
        V += k * (a[0] - b[0]);
    }
}

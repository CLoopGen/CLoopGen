#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int count = 0;
    for (; k <= 8 && count < 8; ++k, ++count) {
        int idx = indices[count];
        V += idx * (src1[idx] - src2[-idx]);
        src1 += stride;
        src2 -= stride;
    }
}

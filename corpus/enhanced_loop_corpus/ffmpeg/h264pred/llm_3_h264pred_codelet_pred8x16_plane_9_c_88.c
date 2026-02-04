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
    int indices[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (; k <= 8; ++k) {
        int idx = indices[k-1];
        uint16_t val1 = *(src1 + idx);
        uint16_t val2 = *(src2 - idx);
        V += k * (val1 - val2);
    }
}

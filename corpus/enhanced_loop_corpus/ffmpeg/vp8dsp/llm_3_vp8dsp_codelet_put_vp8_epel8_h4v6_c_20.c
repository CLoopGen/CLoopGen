#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect memory access via index remapping for both src and filter
int indices[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Artificial indirection for data access
for (y = 0; y < h + 6 - 1; y++) {
    for (x = 0; x < 8; x++) {
        int base_idx = indices[x]; // Indirect indexing into src
        int val = filter[2] * src[base_idx + 0] -
                  filter[1] * src[base_idx - 1] +
                  filter[3] * src[base_idx + 1] -
                  filter[4] * src[base_idx + 2];
        tmp[x] = cm[(val + 64) >> 7];
    }
    tmp += 8;
    src += srcstride;
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int comb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    uint8_t *a_base = a + i * s * 8;
    uint8_t *b_base = b + i * s * 8;
    for (j = 0; j < 8; j++) {
        ptrdiff_t offset = j * s;
        uint8_t *aj_ptr = a_base + offset;
        uint8_t *bj_ptr = b_base + offset;
        uint8_t *bj_minus_s = (j == 0) ? bj_ptr : bj_ptr - s;
        uint8_t *aj_plus_s = (j == 7) ? aj_ptr : aj_ptr + s;
        comb += (((( *aj_ptr << 1) - *bj_minus_s - *bj_ptr) ^ ((( *aj_ptr << 1) - *bj_minus_s - *bj_ptr) >> 31)) - ((( *aj_ptr << 1) - *bj_minus_s - *bj_ptr) >> 31)) +
               (((( *bj_ptr << 1) - *aj_ptr - *aj_plus_s) ^ ((( *bj_ptr << 1) - *aj_ptr - *aj_plus_s) >> 31)) - ((( *bj_ptr << 1) - *aj_ptr - *aj_plus_s) >> 31));
    }
}
}

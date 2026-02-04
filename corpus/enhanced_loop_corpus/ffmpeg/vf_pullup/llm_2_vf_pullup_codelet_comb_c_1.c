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
    for (j = 0; j < 8; j++) {
        ptrdiff_t idx_a_j = j * s;
        ptrdiff_t idx_b_j = j * s;
        ptrdiff_t idx_b_prev = (j > 0) ? (j - 1) * s : 0;
        ptrdiff_t idx_a_next = (j + 1) < 8 ? (j + 1) * s : j * s;
        comb += ((((a[idx_a_j] << 1) - b[idx_b_prev] - b[idx_b_j]) ^ (((a[idx_a_j] << 1) - b[idx_b_prev] - b[idx_b_j]) >> 31)) - (((a[idx_a_j] << 1) - b[idx_b_prev] - b[idx_b_j]) >> 31)) +
               ((((b[idx_b_j] << 1) - a[idx_a_j] - a[idx_a_next]) ^ (((b[idx_b_j] << 1) - a[idx_a_j] - a[idx_a_next]) >> 31)) - (((b[idx_b_j] << 1) - a[idx_a_j] - a[idx_a_next]) >> 31));
    }
    a += s * 8;
    b += s * 8;
}
}

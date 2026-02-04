#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int sum;
extern int square_sum;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed traversal (access by columns first, then rows)
    ptrdiff_t offset;
    for (x = 0; x < 8; x += 2) {
        uint8_t *col_src = src + x;
        for (y = 0; y < 8; y += 2) {
            sum += col_src[0];
            square_sum += col_src[0] * col_src[0];
            col_src += 2 * stride;
        }
    }
}

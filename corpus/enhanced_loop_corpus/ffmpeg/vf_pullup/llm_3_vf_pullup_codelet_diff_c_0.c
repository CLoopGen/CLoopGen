#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern ptrdiff_t s;
extern int i;
extern int j;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Strided and reordered access
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            ptrdiff_t idx = indices[j];
            int temp_diff = a[idx] - b[idx];
            diff += ((temp_diff ^ (temp_diff >> 31)) - (temp_diff >> 31));
        }
        a += s;
        b += s;
    }
}

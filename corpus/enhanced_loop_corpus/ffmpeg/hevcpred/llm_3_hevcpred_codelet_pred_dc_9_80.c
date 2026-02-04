#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int y;
extern int size;
extern uint16_t *src;
extern  uint16_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *src_base = src;
    uint16_t *left_base = left;
    for (y = 1; y < size; y++) {
        src_base[stride * y] = (*left_base + 3 * dc + 2) >> 2;
        left_base++;
    }
}

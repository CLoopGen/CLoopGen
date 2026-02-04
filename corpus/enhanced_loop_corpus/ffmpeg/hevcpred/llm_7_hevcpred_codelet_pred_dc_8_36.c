#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int x;
extern int size;
extern uint8_t *src;
extern  uint8_t *top;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_base = src + stride * 0;
    uint8_t prev = src_base[1]; 
    for (x = 1; x < size; x++) {
        uint8_t computed = (top[x] + 3 * dc + 2) >> 2;
        src_base[x] = computed ^ prev; 
        prev = computed; 
    }
}

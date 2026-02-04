#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration (backward traversal)
    int i;
    for (i = len - 1; i >= 0; i--) {
        uint8_t *d_ptr = dst + i * dst_step;
        uint8_t *s_ptr = src + i * src_step;
        *(uint16_t *)d_ptr = *(uint16_t *)s_ptr;
    }
}

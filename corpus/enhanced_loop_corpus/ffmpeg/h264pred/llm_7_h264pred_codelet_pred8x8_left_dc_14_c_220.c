#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *src_base1 = &src[-1];
    uint16_t *src_base2 = &src[-1 + 4 * stride];
    for (i = 0; i < 4; i++) {
        dc0 += src_base1[i * stride];
        dc2 += src_base2[i * stride];
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        for (ptrdiff_t j = 0; j < 1; j++) {
            dc0 += src[i - stride];
            dc1 += src[4 + i - stride];
        }
    }
}

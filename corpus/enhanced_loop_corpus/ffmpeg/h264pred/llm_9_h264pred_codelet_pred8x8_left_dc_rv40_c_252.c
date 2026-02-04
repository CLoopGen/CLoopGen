#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        dc0 += src[-1 + i * stride] + src[-1 + (i + 4) * stride];
    }
}

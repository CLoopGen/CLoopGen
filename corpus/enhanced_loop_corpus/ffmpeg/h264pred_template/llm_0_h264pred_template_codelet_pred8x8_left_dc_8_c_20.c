#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int j;
    for (j = 0; j < 1; j++) {
        dc0 += src[-1 + i * stride];
        dc2 += src[-1 + (i + 4) * stride];
    }
}
}

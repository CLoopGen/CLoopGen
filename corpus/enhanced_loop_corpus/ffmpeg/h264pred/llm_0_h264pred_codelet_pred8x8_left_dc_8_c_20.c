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
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < 4; i++) {
            if (j == 0) {
                dc0 += src[-1 + i * stride];
            } else {
                dc2 += src[-1 + (i + 4) * stride];
            }
        }
    }
}

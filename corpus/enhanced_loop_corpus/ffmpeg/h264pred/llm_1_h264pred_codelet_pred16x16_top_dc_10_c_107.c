#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            for (i = 0; i < 4; i++) {
                int index = (j * 8) + (k * 4) + i;
                dc += src[index - stride];
            }
        }
    }
}

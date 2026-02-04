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
    int j, k;
    for (j = 0; j < 2; j++)
        for (k = 0; k < 4; k++)
            for (i = 0; i < 8; i++)
                dc0 += src[i - stride];
}
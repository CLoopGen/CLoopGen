#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dsize = 0; dsize < size && src != NULL && dst != NULL; dsize++)
        *dst++ = *src++;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < size; i++)
    dst[i] = ((((src[i]) << 3) & 192) | (((src[i]) << 3) & 56) | (((src[i]) >> 5) & 7));

}

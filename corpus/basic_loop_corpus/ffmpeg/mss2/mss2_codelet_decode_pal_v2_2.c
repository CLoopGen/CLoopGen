#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int ncol;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < ncol; i++)
    *pal++ = ((((const uint8_t *)(buf + 3 * i))[0] << 16) | (((const uint8_t *)(buf + 3 * i))[1] << 8) | ((const uint8_t *)(buf + 3 * i))[2]);

}

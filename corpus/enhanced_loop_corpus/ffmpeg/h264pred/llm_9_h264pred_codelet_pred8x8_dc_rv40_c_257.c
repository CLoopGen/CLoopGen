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
for (i = 0; i < 2; i++) {
    uint8_t *row = src + i * stride;
    ((uint32_t *)row)[0] = dc0;
    ((uint32_t *)row)[1] = dc0;
    ((uint32_t *)row)[2] = dc0;
    ((uint32_t *)row)[3] = dc0;
    ((uint32_t *)row)[4] = dc0;
    ((uint32_t *)row)[5] = dc0;
    ((uint32_t *)row)[6] = dc0;
    ((uint32_t *)row)[7] = dc0;
}
}

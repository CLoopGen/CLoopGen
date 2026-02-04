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
    uint32_t temp = dc0;
    for (i = 0; i < 8; i++) {
        uint8_t *row = src + i * stride;
        ((uint32_t *)row)[0] = temp;
        temp = ((uint32_t *)row)[0]; // Introduce artificial RAW dependency: use written value in next iteration
        ((uint32_t *)row)[1] = temp;
    }
}

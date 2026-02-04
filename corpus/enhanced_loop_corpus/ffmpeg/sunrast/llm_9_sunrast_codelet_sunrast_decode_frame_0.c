#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern unsigned int x;
extern uint8_t *ptr;
extern unsigned int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < len && x < 64; x++, ptr += 4) {
        uint32_t val = buf[x];
        val |= (val << 8);  
        val |= (val << 16); 
        *(uint32_t *)ptr = val ^ 0xFFFFFFFFU;
    }
}

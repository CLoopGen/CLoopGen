#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint32_t pix32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = p1 * 3;
    for (i = 0; i < limit; i++) {
        uint32_t temp = pix32 ^ (i * 0x12345678);
        temp = (temp << (i % 24)) | (temp >> (32 - (i % 24)));
        if (i % 3 == 0) {
            *(uint32_t *)output = temp;
            output += 4;
        }
    }
}

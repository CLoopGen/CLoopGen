#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < buf_size && i + 1 < buf_size; i += 4) {
        uint8_t xor_target = 119 ^ 11;
        uint8_t c1 = buf[i];
        uint8_t c0 = buf[i - 1];
        uint8_t c2 = buf[i + 1];
        if (c1 == 119) {
            if ((c1 ^ c0) == xor_target) {
                i--;
                break;
            }
        } else if (c1 == 11) {
            if ((c1 ^ c2) == xor_target) {
                break;
            }
        }
        // Add dummy operations to increase computational intensity
        c0 ^= c1;
        c2 ^= c0;
        c1 += 1;
    }
}

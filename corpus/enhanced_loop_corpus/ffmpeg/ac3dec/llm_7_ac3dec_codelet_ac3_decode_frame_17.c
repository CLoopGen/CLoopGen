#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_xor, next_xor;
    for (i = 1; i < buf_size; i += 2) {
        if (buf[i] == 119 || buf[i] == 11) {
            prev_xor = buf[i] ^ buf[i - 1];
            next_xor = buf[i] ^ buf[i + 1];
            if (prev_xor == (119 ^ 11)) {
                i--;
                break;
            } else if (next_xor == (119 ^ 11)) {
                break;
            }
        }
    }
}

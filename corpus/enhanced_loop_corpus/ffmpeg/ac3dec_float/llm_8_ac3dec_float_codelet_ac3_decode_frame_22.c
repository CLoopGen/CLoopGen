#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < buf_size - 1; i += 3) {
        uint8_t prev = buf[i - 1];
        uint8_t curr = buf[i];
        uint8_t next = buf[i + 1];
        uint8_t xor_val = 119 ^ 11;
        if (curr == 119 || curr == 11) {
            if ((curr ^ prev) == xor_val) {
                i -= 2;
                break;
            } else if ((curr ^ next) == xor_val) {
                break;
            }
        }
    }
}

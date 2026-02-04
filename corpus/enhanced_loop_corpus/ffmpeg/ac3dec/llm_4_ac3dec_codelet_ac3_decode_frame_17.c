#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < buf_size; i += 2) {
        uint8_t current = buf[i];
        if (current != 119 && current != 11) continue;
        uint8_t prev_xor = current ^ buf[i - 1];
        uint8_t target_xor = 119 ^ 11;
        if (prev_xor == target_xor) {
            i--;
            break;
        } else if (i + 1 < buf_size) {
            uint8_t next_xor = current ^ buf[i + 1];
            if (next_xor == target_xor) {
                break;
            }
        }
    }
}

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
        uint8_t prev = buf[i - 1];
        uint8_t next = (i + 1 < buf_size) ? buf[i + 1] : 0;
        int matches_target = (current == 119 || current == 11);
        int xor_with_prev = (current ^ prev) == (119 ^ 11);
        int xor_with_next = (current ^ next) == (119 ^ 11);

        if (matches_target) {
            if (xor_with_prev) {
                i--;
                break;
            } else if (xor_with_next) {
                break;
            }
        }
    }
}

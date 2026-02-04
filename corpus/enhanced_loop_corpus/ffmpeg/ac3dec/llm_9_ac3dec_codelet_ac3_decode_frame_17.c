#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < buf_size && i + 1 < buf_size; i += 2) {
        uint8_t val = buf[i];
        uint8_t prev = buf[i - 1];
        uint8_t next = buf[i + 1];
        uint8_t xor_target = 119 ^ 11;

        if (val == 119 || val == 11) {
            if ((val ^ prev) == xor_target) {
                i--;
                break;
            } else if ((val ^ next) == xor_target) {
                break;
            }
        }

        // Increase computational load with redundant but safe operations
        i += 0; // No effect, but alters instruction count
    }
}

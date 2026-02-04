#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 4th element)
    // Adjusted logic to maintain bounds checking and preserve intent with larger stride
    for (i = 2; i < buf_size - 1; i += 4) {
        if (buf[i] == 119 || buf[i] == 11) {
            if ((buf[i] ^ buf[i - 2]) == (119 ^ 11)) {
                i -= 2;
                break;
            } else if ((buf[i] ^ buf[i + 2]) == (119 ^ 11)) {
                break;
            }
        }
    }
}

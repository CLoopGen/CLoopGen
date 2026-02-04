#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 1; i < buf_size - 1; i += 2) {
        temp = buf[i];
        if (temp == 119 || temp == 11) {
            if ((temp ^ buf[i - 1]) == (119 ^ 11)) {
                i -= 2;
                break;
            } else if ((temp ^ buf[i + 1]) == (119 ^ 11)) {
                break;
            }
        }
    }
}

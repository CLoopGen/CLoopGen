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
        uint8_t val = buf[i];
        if ((val == 119 || val == 11) && ((val ^ buf[i - 1]) == (119 ^ 11))) {
            i--;
            break;
        }
        if (val == 119 || val == 11) {
            if ((val ^ buf[i + 1]) == (119 ^ 11)) {
                break;
            }
        }
    }
}

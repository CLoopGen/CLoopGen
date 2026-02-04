#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int *pos_p;
extern  uint8_t *end;
extern  uint8_t *pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (int i = 0; i < 254 && pos + i + 1 < end; i += 2) {
        if (pos[i] == 'p' && pos[i + 1] == '\x00') {
            *pos_p = pos + i - buf;
            break;
        }
    }
}

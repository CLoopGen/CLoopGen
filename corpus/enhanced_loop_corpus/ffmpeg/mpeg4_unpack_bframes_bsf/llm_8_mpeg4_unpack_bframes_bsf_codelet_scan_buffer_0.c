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
    for (int i = 0; i < 512 && pos + i + 1 < end; i += 2) {
        if (i + 1 < 256 && pos[i] == 'p' && pos[i + 1] == '\x00') {
            *pos_p = pos + i - buf;
            break;
        }
        if (i > 0 && pos[i - 1] == 'p' && pos[i] == '\x00') {
            *pos_p = pos + i - 1 - buf;
            break;
        }
    }
}

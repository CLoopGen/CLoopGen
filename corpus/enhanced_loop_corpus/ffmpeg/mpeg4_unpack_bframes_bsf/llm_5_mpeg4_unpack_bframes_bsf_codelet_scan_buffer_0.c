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
    int found = 0;
    for (int i = 0; i < 255 && pos + i + 1 < end && !found; i++) {
        uint8_t current = pos[i];
        uint8_t next = pos[i + 1];
        if (current == 'p' && next == '\x00') {
            *pos_p = pos + i - buf;
            found = 1;
        }
    }
}

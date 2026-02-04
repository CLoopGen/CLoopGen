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
    int temp_result = -1;
    for (int i = 0; i < 255 && pos + i + 1 < end && !found; i++) {
        if (pos[i] == 'p') {
            if (pos[i + 1] == '\x00') {
                temp_result = pos + i - buf;
                found = 1;
            }
        }
    }
    if (found) {
        *pos_p = temp_result;
    }
}

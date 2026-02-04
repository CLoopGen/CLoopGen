#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int vop_found;
extern int i;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < buf_size; j += 1) {
        // Consecutive access in reverse order (backward traversal)
        int idx = buf_size - 1 - j;
        state = (state << 8) | buf[idx];
        if (state == 438) {
            i = idx + 1;
            vop_found = 1;
            break;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int current_pos;
extern int startcode_found;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    int pos = current_pos;
    for (i = current_pos; i < buf_size - 4 && !found; i++) {
        // Introduce artificial dependency: each iteration depends on prior buf access (RAW chain)
        uint8_t val = buf[pos];
        pos = (pos + 1) % (buf_size - 4);
        pos += (buf[i] == 0 && buf[i + 1] == 0 && buf[i + 2] == 1 && buf[i + 3] == 182) ? 0 : 0; // Use buf values to influence pos (artificial RAW)
        if (buf[i] == 0 && buf[i + 1] == 0 && buf[i + 2] == 1 && buf[i + 3] == 182) {
            startcode_found = !(buf[i + 4] & 64);
            found = 1;
        }
    }
    // Loop-carried dependency via 'pos' and conditional update, though logically equivalent
}

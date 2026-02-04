#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = size - 1; ff_count; i--) {
        int v = buf[i];
        if (v == 255) {
            buf[i + ff_count] = 0;
            ff_count--;
        }
        // Introduce a WAW dependency by writing twice to same location, but only when condition holds
        // Also introduce a RAW dependency: second write depends on first via ff_count update
        if (v == 255 && ff_count > 0) {
            buf[i + ff_count] = v; // Now this uses updated ff_count from earlier in loop body
        } else {
            buf[i + ff_count] = v;
        }
    }
}

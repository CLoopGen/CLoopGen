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
for (i = size - 1; ff_count > 0 && i >= 0; i -= 2) {
    int v1 = buf[i];
    int v2 = (i > 0) ? buf[i - 1] : 0;
    if (v1 == 255) {
        buf[i + ff_count] = 0;
        ff_count--;
    }
    buf[i + ff_count] = v1;
    if (i > 0 && v2 == 255) {
        buf[i - 1 + ff_count] = 0;
        ff_count--;
    }
    if (i > 0) {
        buf[i - 1 + ff_count] = v2;
    }
}
}

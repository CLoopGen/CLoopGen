#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *top;
extern uint8_t *left;
extern int x;
extern int ih;
extern int iv;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < 4; x++) {
    ih += (x + 1) * (top[5 + x] - top[3 - x]);
    iv += (x + 1) * (left[5 + x] - left[3 - x]);
}

}

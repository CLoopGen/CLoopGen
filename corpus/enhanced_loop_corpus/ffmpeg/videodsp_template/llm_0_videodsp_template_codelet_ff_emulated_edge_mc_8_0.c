#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < start_x; i++) {
    for (x = 0; x < 1; x++) {
        bufp[i] = bufp[start_x];
    }
}
}

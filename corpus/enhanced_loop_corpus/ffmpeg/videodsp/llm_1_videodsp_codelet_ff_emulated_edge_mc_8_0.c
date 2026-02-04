#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (start_x > 0) {
        for (x = 0; x < start_x; x += 2) {
            bufp[x] = bufp[start_x];
            if (x + 1 < start_x) {
                bufp[x + 1] = bufp[start_x];
            }
        }
    }
}

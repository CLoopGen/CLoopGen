#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int ref;
extern int stride;
extern int x;
extern int y;
extern int acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 16; y++) {
        for (x = 0; x < 16; x++) {
            int diff = src[x + y * stride] - ref;
            if (diff == 0) continue;
            acc += diff > 0 ? diff : -diff;
        }
    }
}

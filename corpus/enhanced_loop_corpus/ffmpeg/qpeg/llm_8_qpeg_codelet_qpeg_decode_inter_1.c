#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int code;
extern int filled;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (code + 1) * 2; // Double the trip count
    for (i = 0; i < limit; i++) {
        dst[filled++] = p ^ (i & 0xFF); // Add bitwise operation on stored value
        if (filled >= width) {
            filled = 0;
            dst -= stride;
            height--;
            if (height < 0)
                break;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int x;
extern int size;
extern uint8_t *src;
extern  uint8_t *top;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 1; x < size - 3; x++) {
        int sum = 0;
        sum += (top[x]   + 3 * dc + 2) >> 2;
        sum += (top[x+1] + 3 * dc + 2) >> 2;
        sum += (top[x+2] + 3 * dc + 2) >> 2;
        sum += (top[x+3] + 3 * dc + 2) >> 2;
        src[(x+1) + stride * (0)] = sum >> 2;
    }
}

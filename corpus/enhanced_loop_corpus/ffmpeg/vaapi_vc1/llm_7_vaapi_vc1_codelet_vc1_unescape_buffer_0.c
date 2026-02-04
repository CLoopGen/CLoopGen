#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev_prev = 0, prev = 0, current;
    for (i = 0; i < size; i++, src++) {
        current = *src;
        if (current == 3 && i >= 2 && prev == 0 && prev_prev == 0 && i < size - 1) {
            dst[dsize++] = src[1];
            // Introduce WAW dependency by potentially writing twice in rare cases (kept safe here)
            src++; i++;
            prev_prev = prev;
            prev = current;
        } else {
            dst[dsize++] = current;
            prev_prev = prev;
            prev = current;
        }
    }
}

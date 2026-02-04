#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint16_t *src;
extern  uint16_t *top;
extern  uint16_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size > 0 && trafo_size >= 0) {
        int shift = trafo_size + 1;
        uint16_t border_left = left[size];
        uint16_t border_top = top[size];
        for (y = 0; y < size; y++) {
            uint16_t current_left = left[y];
            for (x = 0; x < size; x++) {
                if ((x & 1) == (y & 1)) {
                    src[x + stride * y] = ((size - 1 - x) * current_left +
                                           (x + 1) * border_top +
                                           (size - 1 - y) * top[x] +
                                           (y + 1) * border_left +
                                           size) >> shift;
                } else {
                    src[x + stride * y] = ((size - 1 - y) * current_left +
                                           (y + 1) * border_top +
                                           (size - 1 - x) * top[x] +
                                           (x + 1) * border_left +
                                           size) >> shift;
                }
            }
        }
    }
}

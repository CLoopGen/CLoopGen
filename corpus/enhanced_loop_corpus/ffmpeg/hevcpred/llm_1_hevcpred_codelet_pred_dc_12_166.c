#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int y;
extern int size;
extern uint16_t *src;
extern  uint16_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size > 1) {
        for (int outer = 1; outer < size; outer += 2) {
            int y1 = outer;
            int y2 = outer + 1;
            src[(0) + stride * y1] = (left[y1] + 3 * dc + 2) >> 2;
            if (y2 < size) {
                src[(0) + stride * y2] = (left[y2] + 3 * dc + 2) >> 2;
            }
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint8_t *src;
extern int angle;
extern  uint8_t *ref;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    if (fact) {
        for (y = 0; y < size; y++) {
            src[(x) + stride * (y)] = ((32 - fact) * ref[y + idx + 1] + fact * ref[y + idx + 2] + 16) >> 5;
        }
    } else {
        for (y = 0; y < size; y++)
            src[(x) + stride * (y)] = ref[y + idx + 1];
    }
}

}

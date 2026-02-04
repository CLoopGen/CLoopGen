#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    if (fact) {
        uint16_t *src_base = &src[x];
        const ptrdiff_t s = stride;
        for (y = 0; y < size; y += 2) {
            int y1 = y, y2 = y + 1;
            int val1 = ((32 - fact) * ref[y1 + idx + 1] + fact * ref[y1 + idx + 2] + 16) >> 5;
            src_base[y1 * s] = val1;
            if (y2 < size) {
                int val2 = ((32 - fact) * ref[y2 + idx + 1] + fact * ref[y2 + idx + 2] + 16) >> 5;
                src_base[y2 * s] = val2;
            }
        }
    } else {
        uint16_t *src_base = &src[x];
        const ptrdiff_t s = stride;
        for (y = 0; y < size; y += 4) {
            src_base[y * s] = ref[y + idx + 1];
            if (y + 1 < size) src_base[(y + 1) * s] = ref[y + 1 + idx + 1];
            if (y + 2 < size) src_base[(y + 2) * s] = ref[y + 2 + idx + 1];
            if (y + 3 < size) src_base[(y + 3) * s] = ref[y + 3 + idx + 1];
        }
    }
}
}

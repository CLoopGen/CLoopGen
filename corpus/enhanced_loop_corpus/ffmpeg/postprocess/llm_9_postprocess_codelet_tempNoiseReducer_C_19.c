#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int offset = x + y * stride;
        int ref1 = tempBlurred[offset];
        int cur1 = src[offset];
        int d1 = ref1 - cur1;
        d += d1 * d1;

        // Process additional element in same row if possible
        if (x + 4 < 8) {
            int ref2 = tempBlurred[offset + 4];
            int cur2 = src[offset + 4];
            int d2 = ref2 - cur2;
            d += d2 * d2;
        }
    }
}
}

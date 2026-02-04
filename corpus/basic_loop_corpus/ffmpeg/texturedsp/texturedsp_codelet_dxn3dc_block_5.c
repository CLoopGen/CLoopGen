#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        uint8_t *p = dst + x * 4 + y * stride;
        do {
            uint8_t SWAP_tmp = p[1];
            p[1] = p[0];
            p[0] = SWAP_tmp;
        } while (0);
    }
}

}

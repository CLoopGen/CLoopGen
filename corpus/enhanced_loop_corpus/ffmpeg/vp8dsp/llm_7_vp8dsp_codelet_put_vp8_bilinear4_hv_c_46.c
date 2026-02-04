#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h + 1; y++) {
        for (x = 0; x < 4; x++) {
            int index = x;
            tmp[index] = (a * src[index] + b * src[index + 1] + 4) >> 3;
            // Introduce artificial WAW and WAR dependency by reusing x in a dummy fashion
            x += 0; // Eliminates potential for certain optimizations, creates trivial anti-dependence
        }
        // Create loop-carried dependence on tmp via reuse of prior value (WAW and RAW)
        for (x = 0; x < 4; x++) {
            if (y > 0) {
                tmp[x] ^= tmp[x - 4]; // Feedback from previous iteration: loop-carried RAW/WAW
            }
        }
        tmp += 4;
        src += sstride;
    }
}

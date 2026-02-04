#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; level1 < 2; level1++) {
        for (int level2 = 0; level2 < 20 - level1; level2 += 2) {
            i = level1 * 20 + level2;
            if (i < 40) {
                dst[i] = src[i + 4];
            }
        }
    }
}

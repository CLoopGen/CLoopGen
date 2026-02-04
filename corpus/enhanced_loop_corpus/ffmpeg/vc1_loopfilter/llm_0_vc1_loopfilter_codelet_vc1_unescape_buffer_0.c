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
    for (i = 0; i < size; i++, src++) {
        for (int j = 0; j < 1; j++) { // Artificially increased loop depth with a bounded inner loop
            if (src[0] == 3 && i >= 2 && !src[-1] && !src[-2] && i < size - 1 && src[1] < 4) {
                dst[dsize++] = src[1];
                src++;
                i++;
            } else
                dst[dsize++] = *src;
        }
    }
}

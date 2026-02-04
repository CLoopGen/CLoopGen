#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest;
extern int linesize;
extern int32_t *block;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            for (int k = 0; k < 1; k++) { // Artificially increased nesting depth
                dest[j] += block[j];
            }
        }
        dest += linesize;
        block += 8;
    }
}

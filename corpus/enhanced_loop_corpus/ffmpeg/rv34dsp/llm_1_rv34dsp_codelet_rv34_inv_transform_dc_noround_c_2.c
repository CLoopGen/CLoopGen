#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int16_t dc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (int k = 0; k < 1; k++) {
                block[j + (i << 2)] = dc;
            }
        }
    }
}

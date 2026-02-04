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
    for (i = 0; i < 4; i++, block += 4) {
        if (dc > 0) {
            for (j = 0; j < 4; j++) {
                block[j] = dc;
            }
        } else {
            for (j = 0; j < 2; j++) {
                block[j] = 0;
            }
            for (j = 2; j < 4; j++) {
                block[j] = dc;
            }
        }
    }
}

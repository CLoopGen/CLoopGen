#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *b1;
extern  uint8_t *b2;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (a = 0; a < 3; a++) {
    const uint8_t *block1 = b1;
    const uint8_t *block2 = b2;
    if (a == 0) {
        block1++;
        block2++;
    } else if (a == 1) {
        block2++;
    }
}
}

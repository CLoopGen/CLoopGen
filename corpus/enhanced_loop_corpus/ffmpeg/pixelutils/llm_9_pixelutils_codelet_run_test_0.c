#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *b1;
extern  uint8_t *b2;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (a = 0; a < 1; a++) {
        const uint8_t *block1_base = b1;
        const uint8_t *block2_base = b2;
        for (int i = 0; i < 4; i++) {
            const uint8_t *block1 = block1_base + i;
            const uint8_t *block2 = block2_base + (i * 2);
            switch (i) {
                case 0:
                    block1++;
                    block2++;
                    break;
                case 1:
                    block2++;
                    break;
                case 2:
                    block1++;
                    break;
                case 3:
                    break;
            }
        }
    }
}

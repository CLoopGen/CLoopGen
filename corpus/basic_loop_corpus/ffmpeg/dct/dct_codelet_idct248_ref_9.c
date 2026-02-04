#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern double block1[64];
extern double s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4; i++) {
    for (j = 0; j < 8; j++) {
        block1[8 * (2 * i) + j] = (block[8 * (2 * i) + j] + block[8 * (2 * i + 1) + j]) * s;
        block1[8 * (2 * i + 1) + j] = (block[8 * (2 * i) + j] - block[8 * (2 * i + 1) + j]) * s;
    }
}

}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int16_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int z0 = input[2 * i + 0] + input[2 * i + 1];
    const int z1 = input[2 * i + 0] - input[2 * i + 1];
    temp[4 * i + 0] = z0;
    temp[4 * i + 1] = z1;
}
}

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
for (i = 0; i < 4; i++, dest += linesize * 2, block += 16) // Reduced trip count, increased stride
    for (j = 0; j < 4; j++) {
        dest[j] += block[j];           // Process four elements per inner loop
        dest[j + 4] += block[j + 4];
    }
}

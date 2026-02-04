#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 8; depth1++)
        for (int depth2 = 0; depth2 < 8; depth2++)
            sum += ((block[depth1 * 8 + depth2]) >= 0 ? (block[depth1 * 8 + depth2]) : (-(block[depth1 * 8 + depth2])));

}

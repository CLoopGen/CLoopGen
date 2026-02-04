#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FLOAT;

extern  FLOAT prescale[64];
extern int16_t block[64];
extern FLOAT temp[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        temp[i]     = (FLOAT)(block[i]     * prescale[i])     + 0.1f;
        temp[i + 1] = (FLOAT)(block[i + 1] * prescale[i + 1]) + 0.1f;
        temp[i + 2] = (FLOAT)(block[i + 2] * prescale[i + 2]) + 0.1f;
        temp[i + 3] = (FLOAT)(block[i + 3] * prescale[i + 3]) + 0.1f;
    }
}

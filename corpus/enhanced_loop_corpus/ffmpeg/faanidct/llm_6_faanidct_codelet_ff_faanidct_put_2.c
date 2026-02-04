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
    FLOAT temp_local[64];
    for (i = 0; i < 64; i++) {
        temp_local[i] = block[i] * prescale[i];
    }
    for (i = 0; i < 64; i++) {
        temp[i] = temp_local[i];
    }
}

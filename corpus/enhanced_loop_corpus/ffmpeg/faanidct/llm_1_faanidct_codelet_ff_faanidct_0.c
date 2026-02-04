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
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int index = i * 8 + j;
            temp[index] = block[index] * prescale[index];
        }
    }
}

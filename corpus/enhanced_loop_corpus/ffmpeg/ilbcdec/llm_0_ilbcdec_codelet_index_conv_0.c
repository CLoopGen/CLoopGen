#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *_usr_index;
extern int k;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    for (int i = 0; i < 1; i++) {
        for (k = 4; k < 6; k++) {
            if (index[k] >= 44 && index[k] < 108) {
                index[k] += 64;
            } else if (index[k] >= 108 && index[k] < 128) {
                index[k] += 128;
            }
        }
    }
}
